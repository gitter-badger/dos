#ifndef KERNEL_SDK_ENGINE_SDK_H
#define KERNEL_SDK_ENGINE_SDK_H

#include <string>
#include <vector>
#include <stdint.h>

namespace dos {

enum SdkStatus {
  kSdkOk,
  kSdkError,
  kSdkParseDescError,
  kSdkNameExist
};

struct CDescriptor {
  // kOci , kDocker
  std::string type;
  std::string uri;
};

struct CInfo {
  std::string name;
  int64_t rtime;
  std::string state;
  std::string type;
};


class EngineSdk {

public:
  static EngineSdk* Connect(const std::string& addr);

  virtual SdkStatus Run(const std::string& name, 
                        const CDescriptor& desc) = 0;
  virtual SdkStatus ShowAll(std::vector<CInfo>& containers) = 0;
};

}

#endif
