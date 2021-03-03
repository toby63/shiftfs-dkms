
# shiftfs-dkms

## Content

* [About](#about)
* [Limitations](#limitations)
* [Status](#status)
* [Usecases](#usecases)
* [Bugreports](#reporting-bugs)
* [Credits](#credits)
* [Copyright](#copyrightlicense)

---

## About

This repo provides scripts to install the (linux-)kernel module **shiftfs** via dkms.   

_Note: shiftfs will maybe be included in the mainline kernel in the future.   
At this point (to my knowledge) only ubuntu included it in their kernel._

### About shiftfs

shiftfs is a kernel filesystem for the linux kernel.   
It provides easier uid/gid-shifting for containers and can be used for example with [LXD](https://linuxcontainers.org/lxd/) (see also: [Usecases](#usecases)).

shiftfs was made by:   
See [Credits](#credits).

* Further information on shiftfs:
https://discuss.linuxcontainers.org/t/trying-out-shiftfs/5155

### Overview of Branches/Versions

There are different versions of shiftfs.c for different kernel versions, so I cover a few of them:

| Branch/Version: | For Kernel(version): | Description: |
| --- | --- | --- |
| [k5.11](https://github.com/toby63/shiftfs-dkms/tree/k5.11) | >=5.11 (5.11 and newer) | - |
| [k5.8](https://github.com/toby63/shiftfs-dkms/tree/k5.8) | >=5.8 & <5.11 (5.8 and newer, but older than 5.11) | - |
| [k5.4](https://github.com/toby63/shiftfs-dkms/tree/k5.4) | >=5.4 & <5.8 (5.4 and newer, but older than 5.8) | - |
| [Arch Linux Package in AUR](https://aur.archlinux.org/packages/?O=0&K=shiftfs) | >=5.11 (5.11 and newer) | Same version as k5.11 |

#### What about older versions?

shiftfs will most likely not work on kernels older than version 5.
Thus the only recent branch newer than 5 is 5.4.
See also [kernel.org](https://www.kernel.org/).


## Limitations

* **Regarding Overlayfs inside container:**   
shiftfs can prevent the use of overlayfs **inside a container**.      
A usecase for this is running Docker with the overlayfs-storage driver **inside a lxd container**.   
A Kernelpatch that solves this is available, but it's not included in the mainline kernel (yet).      
To my knowledge only Ubuntu included it (see [solved bug report](https://bugs.launchpad.net/ubuntu/+source/linux/+bug/1846272)).      

  For **workarounds and more information** see:   
[Issue 2 of this repo](https://github.com/toby63/shiftfs-dkms/issues/2#issuecomment-614688392) 


* More Issues may be found in the [Ubuntu Kernel Bug Tracker](https://bugs.launchpad.net/ubuntu/+source/linux?field.searchtext=shiftfs&search=Search&field.status%3Alist=NEW&field.status%3Alist=INCOMPLETE_WITH_RESPONSE&field.status%3Alist=INCOMPLETE_WITHOUT_RESPONSE&field.status%3Alist=CONFIRMED&field.status%3Alist=TRIAGED&field.status%3Alist=INPROGRESS&field.status%3Alist=FIXCOMMITTED&field.assignee=&field.bug_reporter=&field.omit_dupes=on&field.has_patch=&field.has_no_package=).

## Status

my Project/Repo: | Upstream development: |
--- | --- |
active | active |

If you want to post a testreport, take a look at: [Testreports Issue on Github](https://github.com/toby63/shiftfs-dkms/issues/3).

## Usecases

* LXD:

  How to use shiftfs with LXD is described in [my wiki](https://github.com/toby63/shiftfs-dkms/wiki/Use-shiftfs-in-LXD)     
  and in the official Forum of LXD: [Usecases for shiftfs](https://discuss.linuxcontainers.org/t/lxd-usecases-of-shiftfs-volume-disk-share/7735) and [Trying out shiftfs](https://discuss.linuxcontainers.org/t/trying-out-shiftfs/5155).


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
