### Proxy Design Pattern 

Proxy is a structural design pattern that lets you provide proxy or substitute for another object. A proxy contains the access to the original object. 

Example : 

- Protection Proxy
- Remote Proxy 
- Cache Proxy 
- Virtual Proxy 
- Logging Proxy 


Proxy vs Decorator : 

- Proxy implements the same interface as the original class. 
- Decorator takes function handle of the original function or class. 


Implementation of Cache Proxy 

- Using Cache Proxy you can improve the performance by a lot. 

Example: 

```cpp
[==========] Running 2 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 2 tests from YoutubeManagerTest
[ RUN      ] YoutubeManagerTest.WithoutProxy

Calling Youtube:DB, Need some time
Rendering video page:
Video info for c4340c3d-86d4-4fca-a584-9f4fdaf1a902
Calling Youtube:DB, Need some time
Rendering video page:
Video info for c4340c3d-86d4-4fca-a584-9f4fdaf1a902
Calling Youtube:DB, Need some time
Rendering video page:
Video info for c4340c3d-86d4-4fca-a584-9f4fdaf1a902
Calling Youtube:DB, Need some time
Rendering video page:
Video info for c4340c3d-86d4-4fca-a584-9f4fdaf1a902
Calling Youtube:DB, Need some time
Rendering video page:
Video info for c4340c3d-86d4-4fca-a584-9f4fdaf1a902
Calling Youtube:DB, Need some time
Rendering video page:
Video info for c4340c3d-86d4-4fca-a584-9f4fdaf1a902
Calling Youtube:DB, Need some time
Rendering video page:
Video info for c4340c3d-86d4-4fca-a584-9f4fdaf1a902
Calling Youtube:DB, Need some time
Rendering video page:
Video info for c4340c3d-86d4-4fca-a584-9f4fdaf1a902
Calling Youtube:DB, Need some time
Rendering video page:
Video info for c4340c3d-86d4-4fca-a584-9f4fdaf1a902
Calling Youtube:DB, Need some time
Rendering video page:
Video info for c4340c3d-86d4-4fca-a584-9f4fdaf1a902
Calling Youtube:DB, Need some time
Rendering video page:
Video info for c4340c3d-86d4-4fca-a584-9f4fdaf1a902
Calling Youtube:DB, Need some time
Rendering video page:
Video info for c4340c3d-86d4-4fca-a584-9f4fdaf1a902
Calling Youtube:DB, Need some time
Rendering video page:
Video info for c4340c3d-86d4-4fca-a584-9f4fdaf1a902
Calling Youtube:DB, Need some time
Rendering video page:
Video info for c4340c3d-86d4-4fca-a584-9f4fdaf1a902
Calling Youtube:DB, Need some time
Rendering video page:
Video info for c4340c3d-86d4-4fca-a584-9f4fdaf1a902
Calling Youtube:DB, Need some time
Rendering video page:
Video info for c4340c3d-86d4-4fca-a584-9f4fdaf1a902
Calling Youtube:DB, Need some time
Rendering video page:
Video info for c4340c3d-86d4-4fca-a584-9f4fdaf1a902
Calling Youtube:DB, Need some time
Rendering video page:
Video info for c4340c3d-86d4-4fca-a584-9f4fdaf1a902

[       OK ] YoutubeManagerTest.WithoutProxy (36175 ms)
[ RUN      ] YoutubeManagerTest.WithProxy

Calling Youtube:DB, Need some time
Rendering video page:
Video info for c4340c3d-86d4-4fca-a584-9f4fdaf1a902
Rendering video page:
Video info for c4340c3d-86d4-4fca-a584-9f4fdaf1a902
Rendering video page:
Video info for c4340c3d-86d4-4fca-a584-9f4fdaf1a902
Rendering video page:
Video info for c4340c3d-86d4-4fca-a584-9f4fdaf1a902
Rendering video page:
Video info for c4340c3d-86d4-4fca-a584-9f4fdaf1a902
Rendering video page:
Video info for c4340c3d-86d4-4fca-a584-9f4fdaf1a902
Rendering video page:
Video info for c4340c3d-86d4-4fca-a584-9f4fdaf1a902
Rendering video page:
Video info for c4340c3d-86d4-4fca-a584-9f4fdaf1a902
Rendering video page:
Video info for c4340c3d-86d4-4fca-a584-9f4fdaf1a902
Rendering video page:
Video info for c4340c3d-86d4-4fca-a584-9f4fdaf1a902
Rendering video page:
Video info for c4340c3d-86d4-4fca-a584-9f4fdaf1a902
Rendering video page:
Video info for c4340c3d-86d4-4fca-a584-9f4fdaf1a902
Rendering video page:
Video info for c4340c3d-86d4-4fca-a584-9f4fdaf1a902
Rendering video page:
Video info for c4340c3d-86d4-4fca-a584-9f4fdaf1a902
Rendering video page:
Video info for c4340c3d-86d4-4fca-a584-9f4fdaf1a902
Rendering video page:
Video info for c4340c3d-86d4-4fca-a584-9f4fdaf1a902
Rendering video page:
Video info for c4340c3d-86d4-4fca-a584-9f4fdaf1a902
Rendering video page:
Video info for c4340c3d-86d4-4fca-a584-9f4fdaf1a902

[       OK ] YoutubeManagerTest.WithProxy (2022 ms)
[----------] 2 tests from YoutubeManagerTest (38201 ms total)

[----------] Global test environment tear-down
[==========] 2 tests from 1 test suite ran. (38203 ms total)
[  PASSED  ] 2 tests.
```

Note: 

```
YoutubeManagerTest.WithoutProxy (36175 ms)
YoutubeManagerTest.WithProxy (2022 ms)

```