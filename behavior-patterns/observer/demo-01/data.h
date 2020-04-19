#ifndef DATA_H_
#define DATA_H_

namespace dp {

struct PerformanceData {
  double cpu_ratio;
  double mem_ratio;
  double disk_ratio;

  PerformanceData() : cpu_ratio(0.0), mem_ratio(0.0), disk_ratio(0.0) {}
};

} // namespace dp

#endif // DATA_H_
