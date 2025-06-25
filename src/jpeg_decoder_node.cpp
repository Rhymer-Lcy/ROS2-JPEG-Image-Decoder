#include <rclcpp/rclcpp.hpp>
#include "image_decoder/jpeg_decoder.h"

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<image_decoder::JpegDecoder>());
    rclcpp::shutdown();
    return 0;
}
