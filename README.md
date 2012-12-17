qsvm
====

qt gui and c++ wrapper for libSVM

Right now a lot of functionality is missing. 

The C++ wrapper is able to:
- parse a file in svmlight format and import the samples
- create a svm_problem
- train a model and perform crossvalidation
- open a model

The GUI can:
- show the training data in a table
- plot the points (if in 2d) in a QCustomPlot
- show some information about the training model 
  (need to figure out how to hijack stdout output from libSVM, or how to interpret the model)
