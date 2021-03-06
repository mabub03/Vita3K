#pragma once

#include <cstdint>
#include <mutex>
#include <vector>

struct BitmapAllocator {
    std::vector<std::uint32_t> words;
    std::size_t max_offset;

protected:
    int force_fill(const std::uint32_t offset, const int size, const bool or_mode = false);

public:
    BitmapAllocator() = default;
    explicit BitmapAllocator(const std::size_t total_bits);

    void set_maximum(const std::size_t total_bits);

    int allocate_from(const std::uint32_t start_offset, int &size, const bool best_fit = false);
    void free(const std::uint32_t offset, const int size);
    void reset();

    /**
     * @brief   Get the number of allocated cells from specified region.
     * 
     * @param   offset          Begin offset of the region.
     * @param   offset_end      End offset of the region.
     * 
     * @returns Number of cells already allocated on this region.
     */
    int allocated_count(const std::uint32_t offset, const std::uint32_t offset_end);
};
