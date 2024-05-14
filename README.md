
# shiftfs-dkms version for Kernels 5.18.x

Content:
--------
* [About](#about)
* [Known Issues and Limitations](#known-issues)
* [Status](#status)
* [Howto](#howto)
    * [Install](#install)
    * [Uninstall/Remove](#uninstallremove)
    * [Upgrade](#upgrade)
* [Bugreports](#report-bugs)
* [Credits](#credits)
* [Copyright](#copyrightlicense)


## About

**Note:** This version is compatible with Linux Kernel versions 5.18.x and 5.19.x.

It might also be compatible with 6.0.x, but 6.0.x and 5.19.x are untested.

The **shiftfs.c** file is from the Ubuntu Kinetic kernel repo (lowlatency-next branch), see: [git link](https://git.launchpad.net/~ubuntu-kernel/ubuntu/+source/linux/+git/kinetic/log/fs/shiftfs.c?h=lowlatency-next)

For an overview of shiftfs and more information see [README.md in master branch](https://github.com/toby63/shiftfs-dkms/blob/master/README.md).

## Known Issues

Upstream is warning about potential regressions, if shiftfs is
used with filesystem namespaces.

See: [commit](https://git.launchpad.net/~ubuntu-kernel/ubuntu/+source/linux/+git/jammy/commit/fs/shiftfs.c?h=master-next&id=d347e71d2c0b4fc79891b00c47971f1ac5bd1ca8)

See also the [README.md in master branch](https://github.com/toby63/shiftfs-dkms#known-issues) for more known issues and limitations.

## Status

| Last Update: |
| --- |
| February 2023 |


| Version: | Status: |
| --- | --- | 
| k518 | recent |

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

      # git clone -b k5.18 https://github.com/toby63/shiftfs-dkms.git shiftfs-k518


#### 2. (Optional, but recommended) Update shiftfs.c:

 The shiftfs.c included might be outdated, thus the update-script.
 Check the [upstream log](https://git.launchpad.net/~ubuntu-kernel/ubuntu/+source/linux/+git/kinetic/log/fs/shiftfs.c?h=lowlatency-next) whether an update is available.

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

**Note:** Check for updates regularly in the [upstream log](https://git.launchpad.net/~ubuntu-kernel/ubuntu/+source/linux/+git/kinetic/log/fs/shiftfs.c?h=lowlatency-next) for shiftfs and in the [Update log issue](https://github.com/toby63/shiftfs-dkms/issues/12) for updates of this repo.
 
 * Uninstall/Remove the old version:

   Run as root or with sudo:

       # ./remove1

 * (Optional) Update these scripts:
   
   _Note: Check the GitHub repo whether an update is necessary._
   
   Run as user (inside the scripts folder):
       
       # git pull origin master
 
 * Repeat Step 2. and 3.


## Report bugs

 Report bugs at:
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
