# Developer Log (DEVLOG.md)
## Programming Assignment 2 - Expression Format Detector + Stack Evaluator

---

### Entry 1
**Date:** 2026-03-27  
**Task worked on:** Project setup in GitHub and CLion  
**Issue / Notes:** i created the new public GitHub repository and cloned it into CLion. At first the file was not part of a project target, so I had to create and fix the CMake setup before I could run anything.  
**Testing / Result:** After fixing `CMakeLists.txt`, the project opened correctly and the Run button worked.

---

### Entry 2
**Date:** 2026-03-29  
**Task worked on:** `ArrayStack.h`  
**Issue / Notes:** I first pasted my solution in the wrong way and ended up with duplicate methods and an extra brace. That caused the file to be incorrect.  
**Testing / Result:** I replaced the file with one clean version of the stack methods (`push`, `pop`, `top`, `empty`, `size`) and made sure it matched the teacher template structure.

---

### Entry 3
**Date:** 2026-03-29  
**Task worked on:** Tokenizer  
**Issue / Notes:** I needed the tokenizer to handle multi-digit integers, operators, parentheses, and spaces. The `Token` type in this template only had one field (`value`), so I had to adjust my logic to work with that.  
**Testing / Result:** Tested tokenizing numbers like `42`, operators like `+`, and parentheses. Also made sure spaces were ignored.

---

### Entry 4
**Date:** 2026-03-30  
**Task worked on:** Postfix validation and evaluation  
**Issue / Notes:** I implemented postfix validation using the stack-depth idea, where numbers increase the count and operators decrease it. I also wrote `evalPostfix()` using `ArrayStack<double>`.  
**Testing / Result:** Tested with `3 4 2 * +` and got `FORMAT: POSTFIX` and `RESULT: 11`.

---

### Entry 5
**Date:** 2026-03-31  
**Task worked on:** Infix validation and infix-to-postfix conversion  
**Issue / Notes:** I implemented infix validation by checking whether the expression was expecting an operand or an operator, and by tracking parenthesis balance. Then I wrote the conversion function using operator precedence and a stack.  
**Testing / Result:** Tested with `3 + 4 * 2` and got `FORMAT: INFIX`, `POSTFIX: 3 4 2 * +`, and `RESULT: 11`.

---

### Entry 6
**Date:** 2026-03-31  
**Task worked on:** Final testing and cleanup  
**Issue / Notes:** I tested invalid expressions to make sure they were classified as `NEITHER`. I also checked formatting and commit history.  
**Testing / Result:** Tested `3 + * 4` and got `FORMAT: NEITHER` and `ERROR: invalid expression`. Final code, README, and DEVLOG were all pushed to GitHub.