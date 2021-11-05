
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

This repo provides scripts to install the (Linux) kernel module **shiftfs** via dkms.   

### About shiftfs

shiftfs is a kernel filesystem for the Linux kernel.   
It provides easier uid/gid-shifting for containers and can be used for example with [LXD](https://linuxcontainers.org/lxd/) (see also: [Usecases](#usecases)).

shiftfs was made by:   
See [Credits](#credits)

* Further information on shiftfs can be found in the official LXD Forum:
https://discuss.linuxcontainers.org/t/trying-out-shiftfs/5155

### Important News

The official successor of shiftfs is available, see details below.   

The original shiftfs (the version used in this repo) will still be available for:

- Newer kernel versions until approximately 5.16 (maybe longer): **5.13**, **5.14** and **5.15** ([Source](https://discuss.linuxcontainers.org/t/lxd-4-16-has-been-released/11547/16)).   
- Longterm kernel versions: **5.10** and **5.4**, with support until approximately April 2022 ([Source](https://discuss.linuxcontainers.org/t/shared-folder-between-container-and-host-is-cached/10725/12)).   

See **Overview of Branches/Versions** below for more information on each available version in this repo.   

#### Details about the successor for shiftfs

The new approach called "**idmapped mounts**" is natively included in recent Linux kernels (since kernel version **5.12**) - so no need for dkms-modules in the future.    
Support for the new approach is implemented since LXD version **4.16**, and the transition is seamless, so LXD will automatically switch to the new approach, if available.   
**Note:** For now there are some limitations though, as only **ext4, xfs, vfat and btrfs** (since kernel version **5.15**) are supported as underlying filesystems for containers and volumes. **ZFS and cephfs** are planned to be supported in future kernels or seperately.   
So if you use other filesystems, I recommend to use the original shiftfs for now, until it is fixed.   

Also see:

- Official LXD forum:
    - [Comment 1](https://discuss.linuxcontainers.org/t/shared-folder-between-container-and-host-is-cached/10725/2)
    - [Comment 2](https://discuss.linuxcontainers.org/t/lxd-4-16-has-been-released/11547/13)
    - [Comment 3](https://discuss.linuxcontainers.org/t/shared-folder-between-container-and-host-is-cached/10725/12)
    - [Comment 4](https://discuss.linuxcontainers.org/t/lxd-4-16-has-been-released/11547/16)
    - [Comment 5](https://discuss.linuxcontainers.org/t/lxd-4-16-has-been-released/11547/18)
- [LXD Pull Request](https://github.com/lxc/lxd/pull/8778)

### Overview of Branches/Versions

There are different versions of shiftfs.c for different kernel versions, so I cover a few of them:

| Branch/Version: | For Kernel(version): | Further Notes: |
| --- | --- | --- |
| [k5.13](https://github.com/toby63/shiftfs-dkms/tree/k5.13) | 5.15.x, 5.14.x and 5.13.x | - |
| [k5.10](https://github.com/toby63/shiftfs-dkms/tree/k5.10) | 5.10.x (longterm version) and 5.8.x | - |
| [k5.4](https://github.com/toby63/shiftfs-dkms/tree/k5.4) | 5.4 (longterm version) | - |
| [Arch Linux Packages in AUR](https://aur.archlinux.org/packages/?O=0&K=shiftfs) | for packages linux (5.14) and linux-lts (5.10) | - |

#### What about other kernel versions?

Other kernel versions that are newer than 5.x might work, but there is no guarantee and I will not provide that.
You have the best chances if you search inside the Ubuntu kernel repos and might find a version that matches your kernel version (e.g. [hirsute kernel repo - master next](https://git.launchpad.net/~ubuntu-kernel/ubuntu/+source/linux/+git/hirsute/tree/fs/shiftfs.c?h=master-next) for 5.11).

shiftfs will most likely not work on kernels older than version 5.x.
Thus the only recent and active branch newer than 5 is 5.4.
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
