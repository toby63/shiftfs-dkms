
# shiftfs-dkms version for Kernel 5.8+

Content:
--------
* [About](#about)
* [Limitations](#limitations)
* [Status](#status)
* [Howto](#howto)
    * [Install](#install)
    * [Uninstall/Remove](#uninstallremove)
    * [Upgrade](#upgrade)
* [Bugreports](#reporting-bugs)
* [Credits](#credits)
* [Copyright](#copyrightlicense)


## About

**Note:** 

- This version is only compatible with Linux Kernel version >=5.8 and <5.11 (5.8 and newer, but older than 5.11).
- This version is not tested by me anymore.

The **shiftfs.c** file is from the Ubuntu Groovy kernel repo, see: [git link](https://git.launchpad.net/~ubuntu-kernel/ubuntu/+source/linux/+git/groovy/tree/fs/shiftfs.c)

For an overview and more information see [README.md in master branch](https://github.com/toby63/shiftfs-dkms/blob/master/README.md).

## Limitations

See: [README.md in master branch](https://github.com/toby63/shiftfs-dkms#limitations)

## Status

| Last Updated: |
| --- |
| March 2021 |

| Version: | Status: |
| --- | --- | 
| k58-1 | recent | 

If you want to post a testreport, take a look at: [Testreports Issue on Github](https://github.com/toby63/shiftfs-dkms/issues/3).

## Howto

### Install:

#### Requirements:
 * Required Linux Kernel version (see above)
 * dkms
 * kernel-headers (e.g. Debian package (for 64-bit): linux-headers-amd64)

#### 0. Check whether your kernel already includes shiftfs:

      # modinfo shiftfs

#### 1. Download this repo:
  
 With git:

      # git clone -b k5.8 https://github.com/toby63/shiftfs-dkms.git shiftfs-k58


#### 2. (Optional, but recommended) Update shiftfs.c:

 The shiftfs.c included might be outdated, thus the update-script.

 Run as user:

      # ./update1


#### 3. Compile and install shiftfs with dkms:

 Run as root or with sudo:

       # make -f Makefile.dkms

 Now you can check again, whether shiftfs is activated:

       # modinfo shiftfs

### Uninstall/Remove:  

   Run as root or with sudo:

       # ./remove1
       
### Upgrade:
 
 * Uninstall/Remove the old version:

   Run as root or with sudo:

       # ./remove1

 * (Optional) Update these scripts:
   
   _Note: Check the GitHub repo whether an update is necessary._
   
   Run as user (inside the scripts folder):
       
       # git pull origin master
 
 * Repeat Step 2. and 3.


## Reporting bugs

 Report bugs here:
 https://github.com/toby63/shiftfs-dkms/issues


## Credits

* shiftfs was made by:
   * James Bottomley
   * Seth Forshee <seth.forshee@canonical.com>
   * Christian Brauner <christian.brauner@ubuntu.com>   
   
   (recent info is in the shiftfs.c file (See: footer -> tag: MODULE_AUTHOR))

* Some files are based on the Debian package repo of bbswitch (https://salsa.debian.org/nvidia-team/bbswitch), including:
   * dkms.conf
   * Makefile
   * Makefile.dkms
   
* Special thanks to:
   * Stéphane Graber @stgraber
   * Christian Brauner @brauner   
   
  for the helpful advice.


## Copyright/License

General Public License, Version 2

See: [LICENSE](LICENSE)
