## Exercise: Dynamic Memory Management (25 Points)

The project name of this exercise is **DynamiceMemoryManagement**.

The purpose of this assignment is to apply what you have learned about 
new and delete to practice allocating memory from the heap and giving
the allocated memory back.

### Problem Description

A function, 
`void doDynamicMemoryManagement()` has been created in a file named csv30.cc. It should look
something like this when you first open it:

```cpp
void doDynamicMemoryManagement() {
    // Put your code here to allocate a single LeakProofClass instance

    // Put your code here to allocate an array of LeakProofClass instances

    // Be sure to delete all instances created in this function here.
}
```

Currently, this function is empty. You assignment is to put some code in this function that does the
following.  First, it should allocate a single instance of the class `LeakProofClass` from
the heap. The declaration of this class is provided in the file `csv30.h`. Store this address
in a pointer to `LeakProofClass`. You'll need to delete it later to give it back to the heap. 
Next, allocate an array of the class `LeakProofClass` using the `[]`s. Also store this address
in a pointer to `LeakProofClass`. At the end of the function delete both pointers to give the
memory pack to the heap. Be sure to use the proper delete operator for the array. You should
use the `[]`s just as you did when you allocated the array. 

That's it. If you did everthing correctly, the unit tests should pass.

### Getting Started

The first thing you will need to do is accept the invitation to this 
assignment from GitHub Classroom. You can click 
[here](https://classroom.github.com/a/DV_Jf5Yd) to accept the 
invitation, and get started.

Be sure that you accept the invitation first and use the URL to your new project when you clone it in CLion. After copying
the URL into the clipboard, in CLion click **VCS -> Checkout from Version Control -> Git**. Paste the URL into the **URL** box of the _Clone Repository_ dialog box and press **Clone**.

### Writing the code for this Project

In this project, you are provided with the files `csv30.h` and `csv30.cpp`. The `.h` file
contains the declaration of the function you are going to write. You do not need to change
this file at all. The `.cc` is where you will put the code you need to write for this 
assignment. 

### Running the code for this project

For this project, you don't need to run the main target, just run the unit tests as
described below.

### Testing the code for this project

Testing the code for this project is similar to running your code
as outlined above. In the drop-down menu in the upper right-hand
corner select the target `All in DynamicMemoryManagement_Gtest | Debug` and press the 
play button next to it. In the **Run** view below the code you should
see the output of running these tests. It should look something
like this:

```bash
Testing started at 9:11 PM ...
/tmp/tmp.Cch8RBWczh/cmake-build-debug/../bin/DynamicMemoryManagement_GTest --gtest_filter=* --gtest_color=no
Running main() from gtest_main.cc

Your unit test score is 20 out of 20
The assignment is worth a total of 25 where the remainder of 5 points
comes from grading related to documentation, algorithms, and other
criteria.


Process finished with exit code 0
```

### Pushing your code to GitHub

Now you need to turn in your code by sending, or pushing, your code to GitHub. You created a 
GitHub repository when you started the assignment. Now you need to take your local code changes
and send them to GitHub so that you can turn it in and have it graded in the next step in the
work flow.

The first step is to commit your code locally. This tell git what files you want to turn in. In 
this case you only need to turn in the contents of `csv30.cc`. In the Project view, right-
click **EX06-DynamicMemoryManagement** and then select **Git -> Commit Directory...**. In the dialog box that
pops up, be sure only `grade` is selected and that there is some text in the _Commit 
Message_ box. A good commit message would be something like `Committing code to get a good grade`.

Once the commit is finished, which is a purely local action, you need to send that commit to 
GitHub. This is called the push phase of the process. Again right-click on **EX06-DynamicMemoryManagement**.
Then select **Git -> Repository -> Push**. In the dialog box that pops up, push the **Push** button
and that should be it. You should see a message that says the push was successful. In the next
step you'll confirm that your code is working and then submit it for a grade.

### Turning in and Grading your code

Go back to LazyGrader and login again, if needed. Press the _Build_ button next to 
**EX06-DynamicMemoryManagement** for this course. This will send a command to Jenkins to download your code
from GitHub and test it. If all goes well and all the tests pass, the ball next to the _Build_
will turn blue. If some of the tests don't pass the ball will be yellow. If the ball is grey,
that means you have not run the tests before and your project is not ready for grading.

Once the Jenkins status is blue or yellow, press the _Grade_ button for **EX06-DynamicMemoryManagement**.
This will read the results from Jenkins and send your grade to Canvas. Once the notification in 
LazyGrader says the grade has been posted, you should see your grade on Canvas.

That's it, once you've submitted your grade, you are done. I will add points later, after I
inspect your code. For example, most projects will be out of a total of 25 points, but after 
pressing the _Grade_ button, Canvas will show 20 points. I will add up to 5 points after I have
looked at your code and am conviced it is original.
