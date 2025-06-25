# ROS2-JPEG-Image-Decoder

## ROS2-JPEG-Image-Decoder: A reliable compressed image conversion solution for FAST-LIVO2 ROS2

<p align="center">
  <img src="https://img.shields.io/badge/ROS2-Humble%20|%20Iron-brightgreen" alt="ROS2 Version">
  <img src="https://img.shields.io/badge/Platform-Ubuntu%2022.04|20.04-blue" alt="Platform">
  <img src="https://img.shields.io/badge/OpenCV-4.x-orange" alt="OpenCV">
</p>

Specialized JPEG image decoder package for the optimized [FAST-LIVO2-ROS2-MID360-Fisheye](https://github.com/Rhymer-Lcy/FAST-LIVO2-ROS2-MID360-Fisheye) system, provides a modular alternative to the built-in `LIVMapper::jpeg_callback` method for enhanced compressed image processing.

## 🚀 Key Features
- Replacement for `void LIVMapper::jpeg_callback(const sensor_msgs::msg::CompressedImage::SharedPtr msg)`
- Real-time JPEG-to-RAW image conversion
- Optimized for MID360 fisheye camera streams
- Complete ROS 2 node lifecycle management
- Low-latency OpenCV-based decoding

## ⚙️ Installation & Configuration

### 1. Install Dependencies

```bash
sudo apt install ros-$ROS_DISTRO-image-transport ros-$ROS_DISTRO-cv-bridge
```

### 2. Clone & Build

```bash
cd ~/fast_ws/src
git clone https://github.com/Rhymer-Lcy/ROS2-JPEG-Image-Decoder.git
cd ..
colcon build --symlink-install --packages-select image_decoder
source install/setup.bash
```

### 3. Activate in FAST-LIVO2

Edit mapping_aviz_metacamedu.launch.py and uncomment the decoder node section:
```bash
Node(
    package="image_decoder",
    executable="jpeg_decoder_node",
    name="jpeg_decoder",
    output="screen",
    respawn=use_respawn,
    ),
```