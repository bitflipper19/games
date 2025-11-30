# OpenGL Setup

This project uses **OpenGL**, **GLFW**, and **GLEW** for graphics rendering.
Availability of a C++ compiler is obvious.

## Installation on linux based systems

### Ubuntu/Debian:
```bash
sudo apt update
sudo apt install build-essential cmake
sudo apt install mesa-common-dev libgl1-mesa-dev
sudo apt install libglfw3-dev libglew-dev
```

### Arch/Manjaro:
```bash
sudo pacman -Syu
sudo pacman -S base-devel cmake
sudo pacman -S mesa glfw-x11 glew
```
Note: If using Wayland instead of X11, use ```glfw-wayland``` instead of ```glfw-x11```.

### Fedora/RHEL/CentOS
```bash
sudo dnf install @development-tools cmake
sudo dnf install mesa-libGL-devel glfw-devel glew-devel
```

## Installation on Windows
Installation via wsl is recommended.
```cmd
wsl --install
```

## Installation on macOS
```bash
brew update
brew install cmake glfw glew
```

## To compile
```bash
g++ {fileName}.cpp -o sym -lGL -lglfw -lGLEW
```

## To run
```bash
./sym
```

