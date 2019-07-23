# 俄罗斯方块
大一上学期学完C语言，寒假需要做一个小项目，因为之前工作室的学长给我们演示了一下如何用C语言实现一个贪吃蛇，所以想到自己用C语言实现一个俄罗斯方块。

本来以为不很简单，但因为当时学的东西太少，也是第一次做这种东西，期间遇到了很多问题。刚开始本来想着做一个好看的界面，所以当时到处去查C语言如何能够做出一个好看的界面，查了很久都没有一个结果。最后不知在哪看到c++可以做界面，第二学期也要学c++，于是就想着先学一下。刚开始拿到书时，整体翻了一下，看到书的最后面有介绍MFC！而且可以做界面！！！稍微看了一下，发现好像看不懂！行吧，可能是因为c++基本语法我都不懂，于是就把c++基本语法学习了一遍。再去看MFC，卧槽！！！！还是看不懂！！！最后又挣扎了一下，还是放弃了用c++做界面的想法。最后实在没办法，用一个汉字 "回" 来代表一个小方块，四个 "回" 就可以组成一个方块，机智！

后来，地图和方块都出来了，本来以为地基打好了，后面的就简单了。结果突然发现，方块是有了，怎么移动呢？最后想了很久，才发现可以把原来方块的位置输出空格，这就相当于把原来位置上的方块清除，然后在下一个位置输出方块。当时想着，这样会不会效率不高，出现卡顿的情况？包括当时在处理很多情况时，都会去想一种高效的方法，希望这样做出来的俄罗斯方块能够运行的更流畅。现在想想，当时的我好像有点小看计算机的速度了！

后来一个较大的问题就是方块的变换，因为一共有七种方块，每种方块又有不同的变换，如何高效有序的变换成了一个问题？后来通过比较分析，每个大方块由四个小方块组成，给每个小方块编上号，这样在变换的时候很多方块的变换方式都是一样的。现在想想，这样写其实最大的好处就是去除了大量的重复代码。

再后来的一个问题就是方块消除，当某一行被方块占满时，需要消除该行，并将上面方块整体下移。解决的方法是，使用一个辅助数组，记录每一行有多少个方块，当某一行满时，就消除。再使用一个辅助数组记录每一列最上面的那个方块位置，用于方块整体下移。

### 存在的问题
**方块右下角会有一个白色小光标**
解决办法：因为方块的打印是通过移动光标并打印一个 "回"，所以每次打印完之后光标会停留在最后打印的 "回" 后面。所以可以在每次打印完之后，直接将光标移动至地图末尾。

**方块移动至地图边界时，变换会出现问题**
因为方块变换之后，方块所占的位置会出现变化，所以方块在边界上变换是，可能变换之后的方块会超出边界。
解决办法：在边界上变换时，加一个判断条件，如果变换之后方块超出边界，则整体向中间移动即可。

### 项目截图
<center><img src="https://raw.githubusercontent.com/debugxw/tetris/master/image/tetris_1.png" width="60%" height="60%" /></center>
<center><img src="https://raw.githubusercontent.com/debugxw/tetris/master/image/tetris_2.png" width="60%" height="60%" /></center>
<center><img src="https://raw.githubusercontent.com/debugxw/tetris/master/image/tetris_3.png" width="60%" height="60%" /></center>
<center><img src="https://raw.githubusercontent.com/debugxw/tetris/master/image/tetris_4.png" width="60%" height="60%" /></center>

![tetris_1](https://raw.githubusercontent.com/debugxw/tetris/master/image/tetris_1.png)
![tetris_2](https://raw.githubusercontent.com/debugxw/tetris/master/image/tetris_2.png)
![tetris_3](https://raw.githubusercontent.com/debugxw/tetris/master/image/tetris_3.png)
![tetris_4](https://raw.githubusercontent.com/debugxw/tetris/master/image/tetris_4.png)