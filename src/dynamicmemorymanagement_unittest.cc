// Copyright 2018, Allan Knight.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Allan Knight nor the names of other
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

// A unit tester for EX01-HelloWorld in CSV13 at Ventura College.
//
// Author: aknight@vcccd.edu (Allan Knight)


// Includes for google test and the unit under test.

#include <climits>
#include <cstdint>
#include <iostream>
#include <cstdlib>

#include "csv30.h"

#include "gtest/gtest.h"

namespace {

using namespace ::testing_internal;

class DynamicMemoryManagementFixture : public ::testing::Test {
protected:
    static const uint64_t MAX_TESTED_SCORE = 20;
    static const uint64_t MAX_OVERALL_SCORE = 25;
    static uint64_t _testScore;

protected:

    void SetUp() override {
    }

    void TearDown() override {
    }

    static void TearDownTestCase() {
      if (_testScore == MAX_TESTED_SCORE) {
        std::cout << std::endl << "Your unit test score is "
                               << _testScore << " out of "
                               << MAX_TESTED_SCORE << std::endl;
      } else {
        std::cout << "Your unit test score is "
                  << _testScore << " out of "
                  << MAX_TESTED_SCORE << " ("<< (int)(_testScore - MAX_TESTED_SCORE)
                  << ")" << std::endl;
      }

      std::cout << "The assignment is worth a total of " << MAX_OVERALL_SCORE
                << " where the remainder of 5 points" << std::endl;
      std::cout << "comes from grading related to documentation, algorithms, and other"
                << std::endl;
      std::cout << "criteria." << std::endl << std::endl;
    }
};

uint64_t DynamicMemoryManagementFixture::_testScore = 0;

TEST_F(DynamicMemoryManagementFixture, TestMemoryManagement) {
    doDynamicMemoryManagement();
    ASSERT_TRUE(LeakProofClass::created());
    _testScore += 5;
    ASSERT_LT(1, LeakProofClass::allocated());
    _testScore += 5;
    ASSERT_EQ(0, LeakProofClass::referenced());
    _testScore += 5;
    ASSERT_LE(1, LeakProofClass::singles());
    _testScore += 2;
    ASSERT_LE(1, LeakProofClass::arrays());
    _testScore += 3;
}

}  // namespace

