# version 1.7
import numpy as np
from sklearn.linear_model import SGDRegressor        #导入随机梯度下降
from sklearn.linear_model import ElasticNet      #导入弹性网络回归
from sklearn.linear_model import Ridge     #导入岭回归类
from sklearn.linear_model import Lasso     #导入lasso回归类
from sklearn.linear_model import LinearRegression     #导入线性回归类
from sklearn.preprocessing import PolynomialFeatures    #多项式构造
# from sklearn.model_selection import train_test_split
from sklearn.metrics import mean_squared_error        #导入均方误差评估
from sklearn.metrics import r2_score         #导入评估决定系数，EMS的标准化
import math         #数学
import matplotlib.pyplot as plt    #画图
import time         #时间

# 自建数据集
m=120
x_range = 10

# 训练集
X = np.linspace(0, x_range, m).reshape(m, 1)      #在0到x_range之间创建m个等差数列并转化为m行1列
Y =[]
for index in range(len(X)):         # 执行X次循环
	y = math.cos(X[index])          # 根据X生成对应的余弦Y
	Y.append(y)         # 将y添加到Y所含元素的最后面
Y = np.array(Y)         # 创建一个一维数组
Y = Y.reshape(m, 1) + 0.2*np.random.randn(m,1)     #np.random.randn(m,1)返回一个m行1列的随机数列矩阵

poly_feature = PolynomialFeatures(degree = 6, include_bias=False)      #多项式次数为40，没有零次幂
X_poly = poly_feature.fit_transform(X)       #使X中的数据先拟合再标准化，使数据适应各种标准函数的读取
# 对部分数据先拟合fit，找到该part的整体指标，如均值、方差、最大值最小值等等（根据具体转换的目的），然后对该X进行转换transform，从而实现数据的标准化、归一化等等。

# 测试集
x_test = np.linspace(0, x_range, 100).reshape(100, 1)
Y_text =[]
for index in range(len(x_test)):         # 执行X次循环
	y_text = math.cos(X[index])          # 根据X生成对应的余弦Y
	Y_text.append(y_text)         # 将y添加到Y所含元素的最后面
Y_text = np.array(Y_text)         # 创建一个一维数组
Y_text = Y_text.reshape(100, 1) + 0.2*np.random.randn(100,1)     #np.random.randn(m,1)返回一个m行1列的随机数列矩阵
x_test_poly = poly_feature.fit_transform(x_test)

start = time.clock()
model_1 = LinearRegression()     #线性回归类的实例化
model_1.fit(X_poly,Y)
end = time.clock()
print('多项式 Running time: %s Seconds'%(end-start))

start = time.clock()
model = Ridge(alpha = 3, solver="cholesky")      #岭回归类的实例化，正则化力度为3，使用标准scipy.linalg.solve去得到一个闭合解
model.fit(X_poly,Y)
end = time.clock()
print('ridge Running time: %s Seconds'%(end-start))

start = time.clock()
model_2 = Lasso(alpha = 0.1, max_iter=20000)       #lasso回归类的实例化，L1,正则化系数0.5，最大迭代次数为20000
model_2.fit(X_poly,Y)
end = time.clock()
print('lasso Running time: %s Seconds'%(end-start))

start = time.clock()
model_3 = ElasticNet(alpha=0.1,l1_ratio=0.1)         #弹性网络回归，alpha混合惩罚项常数为0.5相当于k，rkL1+(1-r)L2，l1_ratio混合惩罚项参数即r
model_3.fit(X_poly,Y)
end = time.clock()
print('弹性网络 Running time: %s Seconds'%(end-start))

start = time.clock()
sgd = SGDRegressor()      # 随机梯度下降
sgd.fit(X_poly, Y)
end = time.clock()
print('随机梯度1 Running time: %s Seconds'%(end-start))

start = time.clock()
sgd2 = SGDRegressor(max_iter = 20000)      # 随机梯度下降，最大迭代次数，默认1000
sgd2.fit(X_poly, Y)
end = time.clock()
print('随机梯度2 Running time: %s Seconds'%(end-start))

plt.figure('linear')      #新建一个叫linear的画布
plt.scatter(X, Y)     #绘制X、Y相同长度的散点图
u = model_1.predict(x_test_poly)          #对x_test_poly的数据进行预测
plt.plot(x_test, u)    #绘制回归曲线
# 评估均方误差
print('多项式_MSE test:%.3f' % (mean_squared_error(Y_text,u)))
# 评估决定系数(coefficient of determination)，是MSE的标准化
print('多项式_R^2 test:%.3f' % (r2_score(Y_text,u)))

plt.figure('ridgeL2')
plt.scatter(X, Y)
u = model.predict(x_test_poly)
plt.plot(x_test, u)
# 评估均方误差
print('ridgeL2_MSE test:%.3f' % (mean_squared_error(Y_text,u)))
# 评估决定系数(coefficient of determination)，是MSE的标准化
print('ridgeL2_R^2 test:%.3f' % (r2_score(Y_text,u)))    #1-（预测误差/平均误差），趋于1好，趋于0坏

plt.figure('lassoL1')
plt.scatter(X, Y)
u = model_2.predict(x_test_poly)
plt.plot(x_test, u)
# 评估均方误差
print('lassoL1_MSE test:%.3f' % (mean_squared_error(Y_text,u)))
# 评估决定系数(coefficient of determination)，是MSE的标准化
print('lassoL1_R^2 test:%.3f' % (r2_score(Y_text,u)))

plt.figure('ET')
plt.scatter(X, Y)
u = model_3.predict(x_test_poly)
plt.plot(x_test, u)
# 评估均方误差
print('弹性网络_MSE test:%.3f' % (mean_squared_error(Y_text,u)))
# 评估决定系数(coefficient of determination)，是MSE的标准化
print('弹性网络_R^2 test:%.3f' % (r2_score(Y_text,u)))

plt.figure('sgd')
plt.scatter(X, Y)
u = sgd.predict(x_test_poly)
plt.plot(x_test, u)
# 评估均方误差
print('随机梯度1_MSE test:%.3f' % (mean_squared_error(Y_text,u)))
# 评估决定系数(coefficient of determination)，是MSE的标准化
print('随机梯度1_R^2 test:%.3f' % (r2_score(Y_text,u)))

plt.figure('sgd2')
plt.scatter(X, Y)
u = sgd2.predict(x_test_poly)
plt.plot(x_test, u)
# 评估均方误差
print('随机梯度2_MSE test:%.3f' % (mean_squared_error(Y_text,u)))
# 评估决定系数(coefficient of determination)，是MSE的标准化
print('随机梯度2_R^2 test:%.3f' % (r2_score(Y_text,u)))

plt.show()    #展示画布

