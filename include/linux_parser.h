#ifndef SYSTEM_PARSER_H
#define SYSTEM_PARSER_H
#include <fstream>
#include <regex>
#include <string>

namespace LinuxParser {
// Paths
const std::string kProcDirectory{"/proc/"};
const std::string kCmdlineFilename{"/cmdline"};
const std::string kCpuinfoFilename{"/cpuinfo"};
const std::string kStatusFilename{"/status"};
const std::string kStatFilename{"/stat"};
const std::string kUptimeFilename{"/uptime"};
const std::string kMeminfoFilename{"/meminfo"};
const std::string kVersionFilename{"/version"};
const std::string kOSPath{"/etc/os-release"};
const std::string kPasswordPath{"/etc/passwd"};

// System
float MemoryUtilization();
long UpTime();
std::vector<int> Pids();
int TotalProcesses();
int RunningProcesses();
std::string OperatingSystem();
std::string Kernel();

// CPU
enum CPUStates {
  kUser_ = 0,
  kNice_,
  kSystem_,
  kIdle_,
  kIOwait_,
  kIRQ_,
  kSoftIRQ_,
  kSteal_,
  kGuest_,
  kGuestNice_
};

std::vector<int> CpuUtilization();
long Jiffies();
long ActiveJiffies();
long ActiveJiffies(int pid);
long IdleJiffies();
  
// Additional functions
float CalculateMemoryUtilization(const int& memtotal, const int& memfree);
int GetProcessNumbers(std::string filename, std::regex rgx);
std::string LineByLineRegexGetter(std::string file_location, std::regex rgx, std::string std_return);
  
// Processes
std::string Command(int pid);
int Ram(int pid);
float Cpu(int pid, int uptime);
std::string Uid(int uid);
std::string User(int pid);
long int UpTime(int pid);


  
};  // namespace LinuxParser

#endif