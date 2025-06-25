#ifndef IMAGE_DECODER_JPEG_DECODER_H
#define IMAGE_DECODER_JPEG_DECODER_H

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/compressed_image.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/opencv.hpp>

namespace image_decoder
{

class JpegDecoder : public rclcpp::Node
{
public:
    explicit JpegDecoder(const rclcpp::NodeOptions & options = rclcpp::NodeOptions());

private:
    void callback(const sensor_msgs::msg::CompressedImage::SharedPtr msg);
    rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr publisher_;
    rclcpp::Subscription<sensor_msgs::msg::CompressedImage>::SharedPtr subscription_;
};

}  // namespace image_decoder

#endif  // IMAGE_DECODER_JPEG_DECODER_H
