# the introduction for Hartree Fock

## introduction

Hartree-Fock 是分子轨道的基础理论，其中假设每一个电子的运动都可以描述为单个粒子的函数，这种的粒子的运动不依赖于其他的电子的瞬时的作用。其中简单的Huckel规则的背后就是HF理论的作用在，只是进行很大程度上的术语简化。
在化学上的引入轨道的概念需要重要值得提醒的是，HF 轨道是近似的，只有单电子体系才有最准确的轨道。通过学习HF理论可以很好作为切入点去学习其他的薛定谔的电子方程，比如多体微扰理论，单参考组态香花作用。

## How To Solve the Hartree Fock

HF理论的出现的目的是解决在BO近似下的不含时的电子薛定谔方程

$$

[-\frac{1}{2}\sum_i(\nabla i^2)-\sum_{A,i}\frac{Z_A}{r_{Ai}}+\sum(\frac{Z_A*Z_B}{R_{AB}})+\sum_{A>B}(\frac{Z_A*Z_B}{R_{AB}}\frac{1}{r_{ij}})+\sum_{i>j}\frac{1}{r_{ij}}]\Psi(r;R)=E_{el}\Psi(r;R)

$$

r 是电子坐标，R是核的自由度。上面的式子可以进行简化

$$

[\hat T_e(r)+\hat V_{eN}(r;R)+\hat V_{NN}(R)+\hat V_{ee}(r)]\Psi(r;R)=E_{el}\Psi(r;R)

$$

在BO 近似的条件下给出实际的势能面，只要拥有势能

面我们就可以算分子的平衡构象，振动模式，而波函数$\Psi(R;r)$ 包含偶极矩，极化率等性质。

## Hatree Product

在Hatree Fock 的理论下，其中电子与电子之间的相互作用是0，即$\hat V_{ee}=0$,这样的基础上，整体的哈密顿量是可以进行分离变量操作。如在H-体系下$\Psi(r_1,r_2)=\Psi_H(r_1)\Psi_H(r_2)$其中 $\Psi(r_1,r_2)$ 被称为Hatree Product
但是上面的式子是违反反对称规则的，在空间自旋的轨道坐标，意味着符合反对称的费米子不是仅仅只用三个恐吓关键自由度，还有内生性质的自旋坐标，称之为$\alpha$或者是$\beta$
因此对于一个Hatree Product,加上自旋的项，即$\chi(x)=\phi(r)\alpha$

$$

\Psi_{HP}(x_1,x_2,...,x_N)=\chi_1(x_1)\chi_2(x_2)···\chi_N(x_N)

$$

这个式子不是反对称的，为了实现全同粒子的作用，可以将总的电子波函数写成各个占据分子轨道的Slater 行列式。

## Slater Determinants

针对双电子体系

$$

\Psi(x_1,x_2)=\frac{1}{\sqrt 2}[\chi_1(x_1)\chi_2(x_2)-\chi_1(x_2)\chi_2(x_1)]

$$

$$

\Psi(x_1,x_2)=\frac{1}{\sqrt2}
\left|
\begin{array}{cccc} 
    \chi_1(x_1)  &  \chi_2(x_1) \\ 
    \chi_1(x_2)  &  \chi_2(x_2)   
\end{array}
\right|

$$

将两个原子放在一个轨道上的时候，就是$\chi_1$ 等于$\chi_2$ 的时候，总的轨道等于0.
写成行列式的好处，电子都是无法区分的，这与量子力学的结果是一致的。每个电子都与每个轨道相关联！这一点很容易被遗忘，特别是因为写出整个行列式是很麻烦的，这会提醒我们这种无法区分的。说到这，是时候引入一个更紧凑的符号了

对于占据轨道的行列式可以写成$\{\chi_i(x),\chi_j(x),...,\chi_k(x) \}$ 可以写成为右矢，$|\chi_i\chi_j...\chi_k \rangle$

这里值得注意是，单电子近似不是说每个电子不会感受到其他电子的作用，而是感受的是其他电子的平均相互作用。其中HF和Kohn-Sham 之间存在很多相似之处，差别主要对于哈密顿量的处理不同

## Simplified the Hamiltionian of HF

Fock 算符，单电子在平均场中运动，
$\hat F\phi(r_i)=\epsilon\phi(r_i)$
分解Fock 算符可以分成两个部分，单电子的操作符$h$和双电子操作符$V$

$$

h(i)=-\frac{1}{2}\nabla_i^2-\sum_A(\frac{Z_A}{r_{iA}})

$$

$$

v(i,j)=\frac{1}{r_{ij}}

$$

总的哈密顿量可以写成更加简单的形式

$$

\hat H_{el}=\sum_ih(i)+\sum_{i<j}+V_{NN}

$$

## How to get the energy expression

只有归一化的波函数才是可用的波函数

$$

E_{el}=\langle \Psi|\hat H_{el}|\Psi \rangle

$$



对于对称能量表达，我们可以使用变分法，它指出能量始终是真正能量的上限。因此，我们可以通过改变其参数来获得更好的近似波函数，直到我们最大限度地减少给定功能空间内的能量。正确的分子轨道是那些最大限度地减少电子能量的轨道，可以使用使用格点积分获得或者使用给定基函数的线性组合得到，这里使用基函数不是轨道，而是可以展开轨道的某种数学形式，比如Gaussian 函数

总体的HF 理论表示的能量可以使用下面的式子进行表示

$$

E_{HF}=\sum_i\langle i|h|i \rangle+\frac{1}{2} \sum_{ij}[ii|jj]-[ij|ji]

$$

其中的单电子积分可以使用下面的式子进行表示


$$

\langle \Psi|\Omega|\Psi \rangle

$$

双电子积分

$$

[ij|kl]=\int dx_1 dx_2\chi_i^*(x_1)\chi_j(x_1) \frac{1}{r_{12}}\chi_k^*(x_2)\chi_l(x_2)

$$

只要快速解这两个积分就可以算出能量。

## Hartree-Fock Equation

Hartree-Fock 方法旨在大致解决电子薛定谔方程，它假定波函数可以由一个自旋轨道一个电子组成的单个斯莱特行列式进行近似。由于能量表达是对称的，使用变分法，因此我们知道，具有最低能量的斯莱特行列式素是尽可能接近我们所能得到的单个斯莱特行列式的假定函数形式的真实波函数。Hartree-Fock 方法确定了一组自旋轨道，这些轨道将能量降到最低，并给我们这个"最佳单个行列式"。

$$

\chi_i\rightarrow\chi_i+\delta_{\chi_i}

$$

使用拉格朗日未定乘子法，

$$

L[\{\chi_i\}]=E_{HF}[\{\chi_i\}]-\sum_{ij}\epsilon_{ij}(\langle i|j \rangle-\delta_{ij})

$$

$\epsilon_{ij}$ 是未定的拉格朗日乘子，$\langle i|j \rangle$ 是自旋轨道的重叠积分

$$

\langle i|j \rangle =\int\chi_i^*(x)\chi_j^*(x)dx

$$

将其中的$\delta L=0$,最后可以得到使用HF描述轨道的方法

$$

h(x_1)\chi_i(x_1)+\sum_{j!=i}[\int dx_2|\chi_j(x_2)|^2r_{12}^{-1}]\chi_i(x_1)-\sum_{j!=i}[\int dx_2\chi_j^*(x_2)\chi_i(x_2)r_{12}^{-1}]\chi_j(x_1)=\epsilon_i\chi_i(x_1)

$$

其中的$\epsilon_i$ 是能量的特征值，$\chi_i$ 是轨道
求解Hatree-Fock 方法用的是Roothaan提出来的矩阵形式，其中的计算首先需要给出一个波函数的初猜，使用其构造出来Fock 矩阵，对角化矩阵之后求解得到近似的能量和波函数，然后反复迭代。
在上面的式子中第一个括号里面是库伦相互作用项，第二个括号里面是交换相互作用项。各自定义库伦算子和交换算子

$hi_{\mu}^*(x1)$得到

$$

\sum_{v}C_{vi}\int dx_1\Chi_{\mu}^*(x_1)f(x_1)\Chi_v(x_1)=\epsilon_i\sum_{v}C_{vi}\int dx_1\Chi_{\mu}^*(x_1)\Chi_v(x_1)

$$

其中矩阵元素可以分成两个部分，一个重叠矩阵，一个是Fock 矩阵。
使用简单的矩阵形式进行表示可以是

$$

\sum_{v}F_{\mu v}C_{vi}=\epsilon_i\sum_{v}S_{\mu v}C_{vi}

$$

$$

FC=SC\epsilon

$$
