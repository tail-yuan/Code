### vim

是的，我熟悉 Vim。在 Vim 中，你可以使用一些快捷键来在行首和行尾之间进行切换。

- **行首切换：** 在 Normal 模式下，按下 `^` 键（Shift + 6），光标会移动到当前行的第一个非空字符处。

- **行尾切换：** 在 Normal 模式下，按下 `$` 键，光标会移动到当前行的末尾字符处。

如果你想要从 Insert 模式切换到 Normal 模式，可以按下 `Esc` 键。

Vim 是一款强大的文本编辑器，具有许多常见的操作指令。以下是一些常见的 Vim 操作指令：

1. **插入和编辑文本：**

   - `i`：在当前光标位置插入文本。
   - `I`：在当前行的行首插入文本。
   - `a`：在当前光标位置之后插入文本。
   - `A`：在当前行的行尾插入文本。
   - `o`：在当前行下方插入一个新行并进入插入模式。
   - `O`：在当前行上方插入一个新行并进入插入模式。
   - `r`：替换单个字符。
   - `R`：进入替换模式，可连续替换多个字符。

2. **保存和退出：**

   - `:w`：保存文件。
   - `:q`：退出 Vim。
   - `:wq`：保存并退出。
   - `:q!`：强制退出（放弃修改）。
   - `:w filename`：将文件另存为指定的文件名。

3. **导航和移动光标：**
   - `h`：向左移动一个字符。
   - `j`：向下移动一行。
   - `k`：向上移动一行。
   - `l`：向右移动一个字符。
   - `gg`：跳转到文件开头。
   - `G`：跳转到文件末尾。
   - `:n`：跳转到第 n 行（例如，`:10` 跳转到第 10 行）。

4. **复制、剪切和粘贴：**

   - `yy`：复制当前行。
   - `dd`：剪切当前行。
   - `p`：在光标位置后粘贴文本。
   - `P`：在光标位置前粘贴文本。

5. **撤销和重做：**

   - `u`：撤销上一步操作。
   - `Ctrl + r`：重做撤销的操作。                             

6. **搜索和替换：**

   - `/pattern`：搜索指定模式。
   - `n`：查找下一个匹配。
   - `N`：查找上一个匹配。
   - `:%s/old/new/g`：替换文件中所有的 old 为 new。

7. **选择和删除：**
   - `v`：进入可视模式，可以选择文本。
   - `V`：选择整行。
   - `x`：删除选定的字符。
   - `d`：删除选定的内容。
   - `:%d`：删除整个文件的内容。
