#include "image_decoder/jpeg_decoder.h"  // 使用 .h 扩展名

namespace image_decoder
{

JpegDecoder::JpegDecoder(const rclcpp::NodeOptions & options)
: Node("jpeg_decoder", options)
{
    publisher_ = create_publisher<sensor_msgs::msg::Image>("/camera/left/image_raw", 10);
    subscription_ = create_subscription<sensor_msgs::msg::CompressedImage>(
        "/camera/left/jpeg", 10,
        std::bind(&JpegDecoder::callback, this, std::placeholders::_1));
}

void JpegDecoder::callback(const sensor_msgs::msg::CompressedImage::SharedPtr msg)
{
    try {
        cv::Mat image = cv::imdecode(cv::Mat(msg->data), cv::IMREAD_COLOR);
        if (!image.empty()) {
            auto image_msg = cv_bridge::CvImage(msg->header, "bgr8", image).toImageMsg();
            publisher_->publish(*image_msg);
            RCLCPP_INFO(get_logger(), "Decoded image size: %dx%d", image.cols, image.rows);
        }
    } catch (const std::exception& e) {
        RCLCPP_ERROR(get_logger(), "Error decoding image: %s", e.what());
    }
}

}  // namespace image_decoder

#include "rclcpp_components/register_node_macro.hpp"
RCLCPP_COMPONENTS_REGISTER_NODE(image_decoder::JpegDecoder)
