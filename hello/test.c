/*
 * Copyright (C) 2018 ETH Zurich and University of Bologna
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdio.h>
#include <rt/rt_api.h>

int __rt_fpga_fc_frequency = 		10000000; // e.g. 20000000 for 20MHz;
int __rt_fpga_periph_frequency = 	 5000000; // e.g. 10000000 for 10MHz;

int main()
{
  printf("Hello !\r\n");
  printf("...bye\r\n");

  return 0;
}
