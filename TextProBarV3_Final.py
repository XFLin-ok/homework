# TextProBarV3_Final.py
import time

student_id = "2320110064"  
student_name = "林锡锋"    
scale = 50
# 2. 执行开始时显示当前时间（格式：****年*月*日 *时*分*秒）
current_time = time.strftime("%Y年%m月%d日 %H时%M分%S秒", time.localtime())
print(f"执行开始 [{current_time}] - {student_id}{student_name}".center(scale + 30, "-"))

start = time.perf_counter()

for i in range(scale + 1):
    a = '*' * i
    b = '.' * (scale - i)
    c = (i / scale) * 100
    dur = time.perf_counter() - start
    
    # 1. 使用f-string格式化字符串，替代原有的format方法
    # 格式解析：
    # {c:^3.0f}：进度百分比（3位宽度，居中，无小数）
    # {a}：已完成进度符号
    # {b}：未完成进度符号
    # {dur:.2f}：耗时（2位小数）
    print(f"\r{c:^3.0f}% [{a}->{b}] {dur:.2f}s", end="")
    time.sleep(0.1)

# 3. 执行结束时显示学号姓名和当前时间
end_time = time.strftime("%Y年%m月%d日 %H时%M分%S秒", time.localtime())
print(f"\n[{end_time}] {student_id}{student_name} 执行结束".center(scale + 30, "-"))