# Copyright 2021 Tech Penguineer
# 
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
# 
#     http://www.apache.org/licenses/LICENSE-2.0
# 
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

CC=gcc
SOURCES=$(wildcard src/*.c) $(wildcard src/interpreter/*.c) $(wildcard benchmarks/*.*)
NAME=icicle
CFLAGS=-g -w
BCFLAGS=-g $(SOURCES) $(wildcard benchmarks/*.*)
OS_NAME := $(shell uname -s | tr A-Z a-z)

os_check:
	@echo $(OS_NAME)
	
install: $(src/include/*.h)
	
	make os_check
	sudo $(CC) $(CFLAGS) $(SOURCES) -o /usr/local/bin/$(NAME)

benchmark:
#	$(CC) $(BCFLAGS) -o $(wildcard bin/)ibc

cln:
	-rm bin/*
	-sudo rm /usr/local/bin/$(NAME)

dev:
	-make cln
	-make install
	-make benchmark 

