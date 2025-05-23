# 魔兽世界城市争霸（难度三）

本项目为山东大学c++高级语言程序设计课设，基于魔兽世界背景，模拟红蓝双方指挥部在多个城市中的士兵生成、移动、战斗、武器抢夺与胜负判定。

## 项目简介

- **开发语言**：C++
- **主要内容**：
  - 红蓝双方士兵生成、战斗、胜负判定
  - 武器管理与抢夺机制
  - 狮子逃跑、武士欢呼、士气变化
  - 城市占领与资源争夺

## 项目结构

- `Object` 类：所有对象基类，提供统一编号系统
- `Warrior` 类：士兵抽象基类（Dragon、Ninja、Iceman、Lion、Wolf）
- `Headquarter` 类：指挥部管理士兵调度、生命元管理
- `main.cpp` 文件：程序入口，初始化与流程控制

## 主要功能模块

- 士兵生成机制（根据生命元与兵种顺序）
- 狮子忠诚度逃跑判断
- 士兵城市间行进逻辑
- 战斗与武器使用规则（剑、炸弹、弓箭）
- 武器抢夺与整理
- 士兵欢呼与士气机制
- 战后武器收集与死亡士兵清除
- 指挥部占领胜利判断


## 环境要求

- Windows 系统
- 支持 C++11 及以上标准的编译器（如 Visual Studio ）

## 编译与运行

编译并运行 `main.cpp`


