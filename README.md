## MESA-Autorun
### ZH_CN
MESA-Autorun用于生成不同金属量或不同质量的模型，仅需输入这些参数。
bash脚本用于运行一些inlist_change，目前还未实现自动编写Bash脚本。

使用方法：

#### write_inlist.cpp:

编辑write_inlist.cpp中的incom（不完整inlist文件名称，该文件必须只没有（initial_mass或initial_z）和controls list的结束语），示例不完整inlist文件内容如下图所示
       
        &star_job

        / ! end of star_job namelist

        &controls
                cool_wind_RGB_scheme = 'Reimers'
                cool_wind_AGB_scheme = ''
                Reimers_scaling_factor = 0.4

                xa_central_lower_limit_species(1) = 'h1'
                xa_central_lower_limit(1) = 1e-4

执行`make`编译

执行`./write_inlist`，输入质量，生成完整inlist文件，默认文件名为`inlist_$(mass)M`

#### rn:

编辑rn，在两个DATE命令中填入`inlist_fi $(inlist_name) $(model_name)`（可以填入多行），$(inlist_name)例如inlist_1M，$(model_name)是重命名后模型的名字，这个命令意味着在重命名前生成的模型文件的名字必须为`final.mod`

移动到MESA项目的目录中，执行`./rn`或`./rn nps`，其中nps可以屏蔽pgstar，但屏蔽pgstar需要有文件`inlist`和`inlist_no_pgstar`
