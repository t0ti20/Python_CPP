#ifndef COUNTER_HPP
#define COUNTER_HPP

#include <iostream>

/**
 * @brief A simple Counter class that counts from 1 up to a specified maximum.
 *
 * This class optionally prints debug information if debug mode is enabled.
 */
class Counter
{
public:
    /**
     * @brief Constructs a Counter object.
     * 
     * @param maxNumber The maximum number to count up to.
     * @param debugEnable Set to true to enable debug output.
     */
    Counter(int maxNumber, bool debugEnable = false);

    /**
     * @brief Start counting from 1 to maxNumber.
     */
    void startCounting() const;

private:
    int m_maxNumber;      ///< Maximum number to count
    bool m_debugEnable;   ///< Flag to enable debug messages
};

#endif // COUNTER_HPP
