## “你帮我助”软件项目

### 项目介绍

在疫情期间，各个小区居民发挥互助精神，进行物品交换，互通有无。该程序允许添加物品的信息，删除物品的信息，显示物品列表，也允许查找物品的信息。该程序采用命令行方式使用，用户的数据将储存在userdata.txt中。

### 使用说明

- 最主要的三个文件

  -   exchange.h：包含了物品列表类（itemList），可进行添加、删除、查找物品信息以及显示物品列表的功能。

  -   test.cpp：通过使用物品列表类对软件的使用逻辑进行实现。

  -   userdata.txt：第一次使用时该文件为空。使用者也可自行创立一个空的txt文件并命名为userdata，将其与test.cpp,exchange.h放在同一个文件夹下。开始使用后尽量不要直接修改该文件，以免发生读取错误。

- “你帮我助软件开发”文件夹

本人编写该代码时使用的是Visual Studio，除了上述三个文件外，其余文件都是自动生成的。我也不知道它们会对程序的运行造成什么影响，就把这些文件也一并打包上传了。该文件夹包含了所有与项目相关的文件，如果您也有安装Visual Studio的话，直接点击\你帮我助软件开发\Exchange\Exchange.sln即可运行程序。
