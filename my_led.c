#include <linux/of_device.h>
#include <linux/sysfs.h>
#include <linux/leds.h>

struct myled *mdev; //declared globally

struct myled {
    struct device *dev;
    unsigned int id;
#ifdef CONFIG_LEDS_TRIGGERS
    struct led_trigger *led;  /* activity led */
#endif
    char name[8];
}

led_trigger_register_simple(dev_name(mdev->dev), &mdev->led);



static ssize_t my_led_on(struct device *dev, struct device_attribute *attr, char *buf)
{ 
   ssize_t i = 0;
   
   led_trigger_event(mdev->led, LED_FULL);   
   i += sprintf(buf, "LED is ON\n");
   return i;
}


static ssize_t my_led_off(struct device *dev, struct device_attribute *attr, char *buf)
{ 
   ssize_t i = 0;
   
   led_trigger_event(mdev->led, LED_OFF);   
   i += sprintf(buf, "LED is OFF\n");
   return i;
}
static DEVICE_ATTR(myled_on, 0444, my_led_on, NULL);
static DEVICE_ATTR(myled_off, 0444, my_led_off, NULL); 

static const struct attribute_group myled_att_gr = {
    &dev_attr_myled_on.attr,
    &dev_attr_myled_off.attr,
    NULL
}

static const struct attribute_group myled_att_gr = {
    .name = "myled",
    .attrs = myled_att
};


ret = sysfs_create_group(&mdev->dev.kobj, &myled_att_gr);
if (ret) {
    dev_err(&mdev->dev, "device_create_file failed\n");
    return ret;
}

led_trigger_unregister_simple(mdev->led);



