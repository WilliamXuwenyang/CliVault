# CliVault

一个基于 C++ 开发的轻量级命令行密码与敏感信息保险库。

本项目使用 CMake 构建，通过 `FetchContent` 自动管理第三方依赖（zlib 与 libsodium），无需手动配置繁琐的库环境，拉取代码即可编译运行。

## 环境要求

在开始之前，请确保你的开发环境满足以下条件：

- **操作系统**：Windows 10 / 11
- **编译器与 IDE**：Visual Studio 2022或2026（安装时需勾选“使用 C++ 的桌面开发”工作负载）
- **构建工具**：CMake（VS2022/2026 已自带，无需单独安装）
- **网络环境**：首次配置项目时，CMake 需要从 GitHub 下载依赖源码，请确保网络通畅（**建议提前开启全局代理或系统代理**）。

## 快速开始（拿到项目后你需要做什么）

如果你是第一次拉取本项目，请严格按照以下步骤配置环境：

### 1. 克隆项目
```bash
git clone https://github.com/你的用户名/CliVault.git
cd CliVault
```

### 2. 使用 Visual Studio 打开
直接双击项目根目录，或者在 Visual Studio 2022 中选择“打开本地文件夹”。VS 会自动识别 `CMakeLists.txt` 并加载项目。

### 3. 等待依赖自动下载与配置
首次打开时，Visual Studio 底部的“输出”窗口会显示 CMake 正在配置项目。此时 CMake 会自动下载 zlib 和 libsodium 的源码包并生成构建系统，请耐心等待。

### 4. 编译与运行
依赖下载完成后，在 VS 顶部的下拉框中选择启动项（通常为 CliVault.exe），点击“本地 Windows 调试器”即可开始编译和运行。
