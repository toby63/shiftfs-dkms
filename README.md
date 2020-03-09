
# shiftfs-dkms

Content:
--------
* [About](#about)
* [Limitations](#limitations)
* [Status](#status)
* [Changelog](#changelog)
* [Howto](#howto)
    * [Install](#install)
    * [Uninstall/Remove](#uninstallremove)
    * [Upgrade](#upgrade)
* [Usecases](#usecases)
* [Bugreports](#reporting-bugs)
* [Credits](#credits)
* [Copyright](#copyrightlicense)


About:
------

This repo provides scripts to install the (linux-)kernel module **shiftfs** via dkms.   

_Note: shiftfs will maybe be included in the mainline kernel in the future.   
At this point (to my knowledge) only ubuntu included it in their kernel (see also: [check whether shiftfs is already included](#0-check-whether-your-kernel-already-includes-shiftfs))._

#### Overview of Branches/Versions:

| Branch/Version: | Kernel(version):  | Link: | Description: |
| --- | --- | --- | --- |
| master | <=5.7 | https://github.com/toby63/shiftfs-dkms/  | Contains the shiftfs.c file from the Ubuntu Focal kernel (5.4) repo, compatible for everything <=5.7 |
| kernel-v5.8 | >5.8 | https://github.com/toby63/shiftfs-dkms/tree/kernel-v5.8 | Contains the shiftfs.c file from the Ubuntu Groovy kernel (5.8) repo | 
| Arch Linux Package | >5.8 | https://aur.archlinux.org/packages/?O=0&K=shiftfs | Arch Linux Package on AUR. |

#### About shiftfs:

shiftfs is a kernel filesystem for the linux kernel.   
It provides easier uid/gid-shifting for containers and can be used for example with [LXD](https://linuxcontainers.org/lxd/) (see also: [Usecases](#usecases)).

shiftfs was made by:   
See [Credits](#credits).

* Further information on shiftfs:
https://discuss.linuxcontainers.org/t/trying-out-shiftfs/5155

* The shiftfs.c file included is from the Ubuntu Kernel repo:
https://git.launchpad.net/~ubuntu-kernel/ubuntu/+source/linux/+git/focal/tree/fs/shiftfs.c

 
Limitations:
---------------

* **This branch (master) is not compatible with Linux Kernel(s) 5.8+:**   
See branch https://github.com/toby63/shiftfs-dkms/tree/kernel-v5.8 instead.

* **Regarding Overlayfs inside container:**   
shiftfs can prevent the use of overlayfs **inside a container**.      
A usecase for this is running Docker with the overlayfs-storage driver **inside a lxd container**.   
A Kernelpatch that solves this is available, but it's not included in the mainline kernel (yet).      
To my knowledge only Ubuntu included it (see [solved bug report](https://bugs.launchpad.net/ubuntu/+source/linux/+bug/1846272)).      

  For **workarounds and more information** see:   
[Issue 2 of this repo](https://github.com/toby63/shiftfs-dkms/issues/2#issuecomment-614688392) 


* More Issues may be found in the [Ubuntu Kernel Bug Tracker](https://bugs.launchpad.net/ubuntu/+source/linux?field.searchtext=shiftfs&search=Search&field.status%3Alist=NEW&field.status%3Alist=INCOMPLETE_WITH_RESPONSE&field.status%3Alist=INCOMPLETE_WITHOUT_RESPONSE&field.status%3Alist=CONFIRMED&field.status%3Alist=TRIAGED&field.status%3Alist=INPROGRESS&field.status%3Alist=FIXCOMMITTED&field.assignee=&field.bug_reporter=&field.omit_dupes=on&field.has_patch=&field.has_no_package=).

Status:
-------

**Note:** The Status applies only for this branch.

Repo: | 
------- |
active | 

Working Versions:| 
---------------- | 
master | 

**Testreports:**   

Version: | OS:            | Kernelversion: | Status:    | Date of last test: |
---      | ---            | ---        | ---    | --- |
master   | Arch Linux | 5.7.12-arch1-1 | Runs/Works | 15.08.2020 |


If you want to post a testreport, take a look at: [Testreports Issue on Github](https://github.com/toby63/shiftfs-dkms/issues/3).

### Changelog:

See: [CHANGELOG](CHANGELOG)


Howto:
------

### Install:

#### Requirements:
 * (Recommended) Recent Linux Kernel (>5.0)
 * dkms
 * kernel-headers (e.g. debian package (for 64-bit): linux-headers-amd64)

#### 0. Check whether your kernel already includes shiftfs:

      # modinfo shiftfs

#### 1. Download this repo:
  
 With git:

      # git clone https://github.com/toby63/shiftfs-dkms.git shiftfs-dkms


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
   
   _Note: See [Changelog](https://github.com/toby63/shiftfs-dkms/blob/master/CHANGELOG) whether an update is necessary._
   
   Run as user (inside the scripts folder):
       
       # git pull origin master
 
 * Repeat Step 2. and 3.


Usecases:
---------

* LXD:

  How to use shiftfs with LXD is described in [my wiki](https://github.com/toby63/shiftfs-dkms/wiki/Use-shiftfs-in-LXD)     
  and in the official Forum of LXD: [Usecases for shiftfs](https://discuss.linuxcontainers.org/t/lxd-usecases-of-shiftfs-volume-disk-share/7735) and [Trying out shiftfs](https://discuss.linuxcontainers.org/t/trying-out-shiftfs/5155).


Reporting bugs:
---------------

 Report bugs here:
 https://github.com/toby63/shiftfs-dkms/issues


Credits:
--------

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


Copyright/License:
------------------

General Public License, Version 2

See: [LICENSE](LICENSE)
