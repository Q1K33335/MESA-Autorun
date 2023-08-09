# MESA-Autorun
# ZH_CN
MESA-Autorun用于生成不同金属量或不同质量的模型，仅需输入这些参数。
bash脚本用于运行一些inlist_change，目前还未实现自动编写Bash脚本。

使用方法：
(1)write_inlist.cpp:
编辑write_inlist.cpp中的filename（不完整inlist文件名称，该文件必须只没有（initial_mass或inliial_z）和controls list的结束语），示例不完整inlist文件内容如下图所示
        &star_job

        / ! end of star_job namelist

        &controls
                cool_wind_RGB_scheme = 'Reimers'
                Reimers_scaling_factor = 0.4
                cool_wind_AGB_scheme = ''

                xa_central_lower_limit_species(1) = 'h1'
                xa_central_lower_limit(1) = 1e-4
执行`make`编译
执行`./write_inlist`，输入质量，生成完整inlist文件，默认文件名为`inlist_$(mass)M`
