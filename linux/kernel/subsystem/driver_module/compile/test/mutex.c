#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/string.h>
#include <linux/uaccess.h>

#define DEV_NAME "test_mutex"

struct test_mutex_dev {
	dev_t dev_no;
	char *dev_name;
	struct cdev *cdev;
}mutex_dev;

static int mutex_open(struct inode *inode, struct file *filp)
{
	printk("open file\n");
	return 0;
}

static ssize_t mutex_read(struct file *filp, char __user *buf, size_t count, loff_t *f_ops)
{
	copy_to_user(buf, "lixunwei", 8);
	return 8;
}

static const struct file_operations mutex_fops = {
	.owner = THIS_MODULE,
	.open = mutex_open,
	.read = mutex_read,
};

static int __init mutex_test_init(void)
{
	int ret;
	mutex_dev.dev_name = kstrdup(DEV_NAME, GFP_KERNEL);
	ret = alloc_chrdev_region(&mutex_dev.dev_no, 0, 10, mutex_dev.dev_name);
	mutex_dev.cdev = cdev_alloc();
	cdev_init(mutex_dev.cdev, &mutex_fops);
	mutex_dev.cdev->owner = mutex_fops.owner;
	cdev_add(mutex_dev.cdev, mutex_dev.dev_no, 10);

	return 0;
}

static void __exit mutex_test_exit(void)
{
	cdev_del(mutex_dev.cdev);
	unregister_chrdev_region(mutex_dev.dev_no, 10);
}

module_init(mutex_test_init);
module_exit(mutex_test_exit);
MODULE_LICENSE("GPL v2");
