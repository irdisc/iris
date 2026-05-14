# Iris+
Iris+ is tool for **Scaning Port** or **Domain Resolveing** and **Subdomain Finder**. Program made in **C** and **CPython.**

- [Features](#key-features)
- [Installer](#install-scripts)
- [UnInstaller](#to-uninstall-use-uninstallersh)
## Requirements
* [**CPython 3.15**](https://github.com/python/cpython)
## Debian base system
```bash
sudo apt install build-essential
```
## Debian base system SSL Headers
```bash
sudo apt install libssl-dev zliblg-dev
```
## Arch base system
```bash
sudo pacman -S base-devel
```
---
## CPython 3.15
```bash
# Explicity command the configuration tool to include OpenSSL support
.configure --with-openssl --enable-optimizations

# Compile using all available CPU processing cores
make -j$(nproc)

# Reinstall the binaries over your current /usr/local environment
sudo make altinstall

```
---
## ✨ Key Features
                        
*   **Port Scan** You can easyliy run it By use this command, Optional you can use TCP `<-tcp>` or UDP `<-udp>`  and IPV6 `<-ipv6>` 
```bash
./iris -scan -tcp <ip>.
```
*   **Down line plan to add more:** see you soon..
*   **Lightweight Design:** Focuses on CPU Usage and RAM Usage.


---

## 🚀 Quick Start

Use the following
installation command:

---
```bash
# Example installation (Keep you git install)
git clone https://github.com/transcrimee/iris+.git && cd iris+ 
```
---
### Install Scripts
```bash
# Then run install.sh
./intall.sh 
```
---
#### Or 
```bash
# Then run mkdir
mkdir -p build 
```
--- 
#### Next
```bash
# Then run make
make install
```
---
#### To Uninstall. use *uninstaller.sh*
```bash
# Install Scripts
./uninstaller.sh
```
---
<p align="center">
  <a href="https://transcrime.com"> Website</a> •
  <a href="crime@theft.bio">Email</a> •
  <a href="https://www.linkedin.com/in/transcrime">LinkedIn</a>
</p>
<p align="center">
  <a href="LICENSE-MIT">License: MIT</a><a href="LICENSE"> | PROPRIETARY LICENSE</a>
</p>
</p>
