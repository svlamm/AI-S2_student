def call_1(x):
    call_2(x)


def call_2(x):
    call_3(x)


def call_3(x):
    print(x[0])
    call_4(x)


def call_4(x):
    print(x['a'])


call_1({'a': 5})
call_1([{'a': 5}])
