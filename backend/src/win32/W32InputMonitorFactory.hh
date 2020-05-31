// W32InputMonitorFactory.hh --- Factory to create input monitors.
//
// Copyright (C) 2007 Rob Caelers <robc@krandor.nl>
// All rights reserved.
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#ifndef W32INPUTMONITORFACTORY_HH
#define W32INPUTMONITORFACTORY_HH

#include <stdlib.h>
#include <string>

#include "IInputMonitorFactory.hh"

//! Factory to create input monitors.
class W32InputMonitorFactory : public IInputMonitorFactory
{
public:
  W32InputMonitorFactory();
  virtual void init(const char *display);
  virtual IInputMonitor *get_monitor(MonitorCapability capability);

private:
  IInputMonitor *create_statistics_monitor();
  IInputMonitor *create_activity_monitor();


private:
  IInputMonitor *activity_monitor;
  IInputMonitor *statistics_monitor;

  std::string actual_monitor_method;
};

#endif // W32INPUTMONITORFACTORY_HH
