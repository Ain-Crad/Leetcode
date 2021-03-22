### 预定类OOD

- Restaurant reservation system
- Hotel reservation system
- Flight/Bus/Train reservation system

#### 解题思路
1. What

    考虑预定的东西
    ```
    Example : 机票

    机舱/座位号/时间
    ```
2. Use case

    - Search
    - Select
    - Cancel

    ![reservation](./imgs/22.png)

3. Class

    ![restaurant_reservation](./imgs/25.png)

#### Example: Hotel reservation system

1. Clarity

    ![restaurant_reservation](./imgs/26.png)

    ![restaurant_reservation](./imgs/27.png)

    ![restaurant_reservation](./imgs/28.png)

    ![restaurant_reservation](./imgs/29.png)

2. Core object

    ![restaurant_reservation](./imgs/30.png)

3. Use case

    **Search, Select, Cancel**

    ![restaurant_reservation](./imgs/31.png)

4. Class
    
    根据Use case中的内容来扩充类图

    ![restaurant_reservation](./imgs/32.png)

    ![restaurant_reservation](./imgs/34.png)

    加分项：使用 **LRU Cache** 来加速查询过程

    ![restaurant_reservation](./imgs/37.png)

    ![restaurant_reservation](./imgs/33.png)

    ![restaurant_reservation](./imgs/35.png)

    Cancel reservation

    ![restaurant_reservation](./imgs/36.png)


