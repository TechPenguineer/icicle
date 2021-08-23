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
SOURCES=$(wildcard src/*.c)
NAME=icicle
CFLAGS=-g $(SOURCES) 

install: include/%.h
	$(CC) $(CFLAGS) -o $(wildcard bin/)icicle

benchmark:
	$(CC) $(CFLAGS) -o $(wildcard bin/)ibc

cln:
	-rm out/*

dev:
	-make cln
	-make install
	-make benchmark 

