/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/11/08 17:21:00

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "bcrypt/bcrypt.h"
#include <iostream>
#include <string>

#include "gtest/gtest.h"

TEST(BcryptTest, TestBcrypt) {
	// 测试加密密码
	std::string password = "123456";
	std::string encodePwd = bcrypt::generateHash(password);
	std::cout << "encodePwd: " << encodePwd << std::endl;

	// 测试校验密码
	ASSERT_EQ(bcrypt::validatePassword(password, encodePwd), true);

	// 测试校验Java加密工具生成的密码
	encodePwd = "$2a$10$K7U.Xolbbz3fGsAzpIawmeQuTWt/W0TXA8DpugqRwWsE0PeRSi1Vu";
	ASSERT_EQ(bcrypt::validatePassword(password, encodePwd), true);
	ASSERT_EQ(bcrypt::validatePassword("12345678", encodePwd), false);
}
