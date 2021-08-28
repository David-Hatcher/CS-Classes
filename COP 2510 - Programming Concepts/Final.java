/*
##########INHERITANCE##########
  Inheritance lets you create a new class based on an existing class. Then, the new class inherits the fields and methods of the existing class.

  A class that inherits from an existing class is called a derived class, child class, or subclass. a class that another class inherits is called 
a base class, parent class, or superclass

  A sinclass can extend the superclass by adding new fields and methods to the superclass. It can also override a method from the superclass with its own version of the
method.

  The object class in java.lang package is the superclass for all classes. In other words, every class inherits the Object class or some other class that ultimately inherits 
the Object class. As a result, the methods defined by the object class are available to all classes.abstract

  When coding classes, it's recommended to override the toString method so that it returns a string that's consise, informative, and easy for a person to read.

  Access modifiers specify the accessibility of the members declared by a class.

  Protected members are accessible to the current class, other classes in the same package, and subclasses.

  An annotation of a standard way to provide information about your code. When you override a method, you can add the @Override annotation to the method.

  YOu can directly access fields that have public or protected access in the superclass from the subclass

  You can extend the superclass by adding new fields and methods to the subclass

  You can override the public and protected methods in the superclass by coding methods in the subclass that have the same signatures as the methods in the superclass.
However, you can't override private mathods in the superclass because they aren't available to the subclass.

  You use the super keyword to call a constructor or method of the superclass. If you call a constructor of the superclass, it must be the first statement of in the constructor
of the subclass.

  Polymorphism is a feature of inhereitance that lets you treat objects of different subclasses that are derived from the same superclass as if they had the tyoe
of the superclass. If, for example, Book is a subclass of Product you can treat a Book object as if it were a Product object.

  If you access a method of a superclass object and the method is overridden in the subclasses of that class, polymorphism determines which method is executed based
on the object's type. For example, if you call the toString method of a Product object, the toString method of the Book class is executed if the object is a Book object.

  Java can implicitly cast a subclass to a superclass. As a result, you can use a subclass whenever a reference to its superclass is called for. For example,
you can specifiy a Book object whenever a Product object is expected because Book is a subclass of Product.

  You must explicitly cast a superclass object when a reference to one of its subclasses is required. For example, you must explicitly cast a Product object to
Book if a Book object is expected. This only works if the Product object is a valid Book object. Otherwise, this throws a ClassCastException.

  Casting affects the methods that are available from an object. For example, if you store a Book object in a Product variable, you can't call the setAuthor method because
it's defined by the Book class, not the Product class.

  You can use the instanceof operator to check if an object is an instance of a particular class.

  To test if two objects variables refer to the same object, you can use the equals method of the Object class.

  To test if two objects store the same data, you can override the equals method in the subclass so it tests whether all instance variables in the two objects are equal.

  Many classes from the Java API (such as the String class) already override the equals method to test for equality.

  An abstract class is a class that can be inherited by other classes but that you can't use to create an object. To declare an abstract class, code the abstract keyword 
in the class declaration.

  An abstract class can contain fields, constructors, and methods just like the other superclasses. In addition, an abstract class can contain abstract methods.

  To create an abstract method, you code the abstract keyword in the method declaration and you omit the method body. Abstract methods cannot have private access.
However, they may have protected or default access(no access modifier).

  When a subclass inherits an abstract class, all abstract methods in the abstract class must be overriden in the subclass. Otherwise the subclass must also be abstract.

  An abstract class doesn't have to contain abstract methods. However, any class that containts an abstract method must be declared as abstract.

  To prevent a class from being inherited, you can create a final class by coding the final keyword in the class declaration

  To prevent a subclass from overriding a method of a superclass, you can create a method bny coding the final keyword into the method declaration. In addition, all methods
in a final class are auctomatically final methods.

  To prevent a method from assigning a new value to a parameter, you can code the final keyword in the parameter declaration to create a final parameter. Then, if a statement
in the method tries to assign a new value to the parameter, the compiler reports an error.
^^^^^^^SUMMARY^^^^^^^

  Inheritance lets you create a new class based on an existing class. The existing class is called the superclass, base class, or parent class, and the new class is called the
subclass, derived class, or child class.

  A subclass inerhits all the fields and methods of it's superclass that aren't private. The subclass can extend the superclass by adding it's own fields and methods, and it can
override a method with a new version of the method.

  All classes inherit the java.lang.Object class. This class provides methods, such as the toString and equals methods, that are available to all classes.

  You can use access modifiers to limit the accessibility of the fields and methods declared by a class. Protected members can be accessed only by classes in the same package
or by subclasses.

  An annotation is a standard way to provide information about your code to other software tools and developers. When you override a method, it's generally considered a good
practice to add the @Override annotation to the method.

  In a subclass, you can use the super keyword to access the fields, constructors, and methods of the superclass.

  Polymorphism is a feature of inheritance that lets you treat subclasses as though they were their superclass.

  java can imlicitly cast a subclass type to its superclass type, but you must use explicit casting to cast a superclass type to a subclass type.

  You can use the instanceof operator to check if an object is an instance of a particular class.

  Abstract classes can be inheritited by other classes but can't be used to create an object. Abstract classes can include abstract methods.

  If you extend an abstract class, you must implement all abstract methods. Otherwise, you must also declare you class as abstract.

  You can use the final keyword to declare final class, final methods, and final parameters. No class can inherit a final class, no method can override a final method, and no 
statement can assign a new value to a final parameter.


##########FILE I/O#########

  To work with a directory or file, you can use a Path object. A Path object can include a root component as well as directory names and a file name.

  Java 7 introduced the java.nio.jile package (also known as NIO.2). This package provides an improved way to access the default file system and is designed to replace the
functionality that was available from the java.io.File class.

  The java.nio.file package provides support for many features that aren't provided by the java.io.File class.

  When coding paths, you can use a front slash to separate directory names. This works equally well for windows and other operating systems.

  To identify the name and location of a file, you can use absolute path name to specify the entire path for a file. You can also use a relative path name to specify the path
of the file relative to the current working directory (CWD). This is usally but not always the directory that the application was started from.

  Although the java.nio.file package was introduced with Java 7, the java.nio package was introduced with Java 4.

  An input file is a file that is ready by an application. An output file is a file that is written by an application. Input and output operations are often referred to as I/O
operations or file I/O.

  A stream is the flow of data from one location to another. To write data to a file from internal storage, you use an output stream. To read from a file into internal storage
You use an input stream.

  To read and write text files, you use character streams. To read and write binary files, you use binary streams.

  Streams are not only used with disk devices, but also with input devices like keyboards and network connections and output devices like PC monitors and network connections.

  The java.io package contains dozens of classes that can be used to work with different types of streams that have different functionality.

  To get the functionality you need for a stream, you often need to combine, or layer, two or more streams.

  To make disk processing more efficient, you can use a buffered stream that adds a block of internal memory called a buffer to the stream.

  When working with buffers, you often need to flush the buffer. This sends all data in the buffer to the I/O device. One way to do this is to use a try-with-resources statement
to automatically close the I/O stream after you use it.

  The Writer class is an abstract class that's inherited by all of the classes in the writer hierarchy. To learn more about the Writer hierarchy, see the Java API Docs.
  
  If the output file doesn't exist when the FileWriter object is create, it's created automatically. If it does exist, it's overwritten by default. If that's not what you want,
you can specify true for the second argument of the constructor to append data to the file.

  If you specify true for the second argument of the PrintWriter constructor, the autoflush feature flushes the buffer each time the println method is called.

  To write a character representation of a data type to an output stream, you can use the print and println methods of the PrintWriter class. If you supply an object as an 
argument, these methods call the toString method of the object.

  To create a delimited text file, you delimit the records or rows in the file with one delimiter, such as a new line character, and you delimite the fields of columns of each
record with another delimiter, such as a tab character.

  To flush all the data to the file you can use a try-with-resources statement to automatically close the stream when you're done using it. You can also use the flush or close
methods of the stream to manually flush all data to the file.

  The Reader class is an abstract class that's inherited by all of the classes in the Reader hierarchy. To learn more about the Reader hieryarchy, check the documentation
for the Java API. All classes in the java.io package that end with Reader are members of the Reader hierarchy.

  Although you can read files with the FileReader class alove, the BufferedReader class improves efficiency and provices better methods for reading character input streams.

^^^^^^^^^^SUMMARY^^^^^^^^^^

  A text file stores data as characters. A binary file stores data in a binary format.

  In a delimited text file, delimiters are used to separate fields and records of the file.

  You can use character streams to read and write text files. To get the functionality you need, you can layer two or more streams.

  A buffer is a block of memory that is used to store data in a stream before it is writter to or after it is read from an I/O device. When an output buffer is full, its data
is flushed to the I/O device.

  When you work with I/O operations, you'll need to catch or throw three types of checked exceptions: IOException, FileNotFoundException, and EOFException.

  To identify a file when you create a File object, you can use an absolute path name or a relative path name.

  The java.nio.file package provides classes and interfaces that you can use to check whether a file or directory exists, to get information about a path, to create or delete
directories and files, and to create a File object.

  You can use the classes in the Writer and Reader hierarchies to work on a text file.
  
########EXCEPTIONS AND TRY/CATCH###########

  An exception is an object of the Exception class or any of its subclasses. It represents a condition that prevents a method from successfully completing.

  The exception class is derived from a class named Throwable. Two types of exceptions are derived from the Exception class: checked and unchecked.

  Checked exceptions are handled by the compiler. As a result, you must write code that handles all checked exceptions before you can compile your code.

  Unchecked exceptions are not checked by the compiler, but they can occur at runtime. It's generally considered a good practice to write code that handles all unchecked exceptions
If an unchecked exception occurs and isn't handled by your code, you application terminates.

  Like the Exception class, the Error class is also derived from the throwables class. However, the Error class identifies internal errors that are rare and can't usually be 
recovered from. As a result, you can usually ignore the Error class.
*/