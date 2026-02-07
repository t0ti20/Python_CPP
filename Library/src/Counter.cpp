#include "Counter.hpp"

Counter::Counter(int maxNumber, bool debugEnable)
    : m_maxNumber(maxNumber), m_debugEnable(debugEnable)
{
    if (m_debugEnable) {
        std::cout << "[DEBUG] Counter initialized with maxNumber = "
                  << m_maxNumber << std::endl;
    }
}

void Counter::startCounting() const
{
    for (int i = 1; i <= m_maxNumber; ++i) {
        
        if (m_debugEnable) {
            std::cout << "[DEBUG] Printed number: " << i << std::endl;
        }
    }

    if (m_debugEnable) {
        std::cout << "[DEBUG] Counting finished." << std::endl;
    }
}
