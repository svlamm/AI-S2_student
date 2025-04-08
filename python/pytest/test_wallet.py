# Source: https://semaphoreci.com/community/tutorials/testing-python-applications-with-pytest
import pytest
from wallet import Wallet, InsufficientAmount


def test_setting_initial_amount():
    wallet = Wallet(20)
    assert wallet.balance == 20


def test_wallet_add_cash():
    wallet = Wallet(20)
    wallet.add_cash(80)
    assert wallet.balance == 100


def test_wallet_spend_cash():
    wallet = Wallet(20)
    wallet.spend_cash(10)
    assert wallet.balance == 10


@pytest.fixture
def empty_wallet():
    return Wallet()


def test_default_initial_amount(empty_wallet):
    assert empty_wallet.balance == 0


def test_wallet_insufficient_amount(empty_wallet):
    with pytest.raises(InsufficientAmount):
        empty_wallet.spend_cash(100)


@pytest.mark.parametrize("earned, spent, expected", [
    (30, 10, 20),
    (20, 2, 18),
])
def test_transactions(empty_wallet, earned, spent, expected):
    empty_wallet.add_cash(earned)
    empty_wallet.spend_cash(spent)
    assert empty_wallet.balance == expected
