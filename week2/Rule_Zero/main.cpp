#include <cstddef>
#include <memory>

class Buffer {
private:
    std::size_t size_{0};
    std::unique_ptr<int[]> data_;

public:
    explicit Buffer(std::size_t n)
        : size_(n),
          data_(n ? std::make_unique<int[]>(n) : nullptr) {}

    std::size_t size() const {
        return size_;
    }
};