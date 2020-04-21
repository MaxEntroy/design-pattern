#ifndef APP_DATA_H_
#define APP_DATA_H_

namespace dp {

struct ApplicationData {
  double cpu_ratio;
  double mem_ratio;
  double disk_ratio;

  ApplicationData() : cpu_ratio(0.0), mem_ratio(0.0), disk_ratio(0.0) {}
};

} // namespace dp

#endif // APP_DATA_H_
