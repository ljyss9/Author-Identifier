# Author-Identifier
这是基于行文特征的作者识别工具，首先使用分词系统NLPIR对文章进行分词，并对文章结构有初步的处理，然后，进行特征提取，提取了词频，标点，句类，以及文章结构这四大类特征,共500左右特征。然后通过改进结合KNN算法和k-means算法的KMN算法进行分类，判断文章可能的作者。

工具后期还用adaboost 算法与信息增益分别对文章用例与特征赋予权重,提高系统检测正确率至85.22%。

此项目参加全国大学生信息安全竞赛，并获得二等奖。
