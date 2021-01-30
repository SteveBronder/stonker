# Stonker: A Trading Engine

Stonker is an framework for live trading and strategy backtesting.

This project hasn't started yet, but I figured why not put it up

## Example:

```cpp
// What does the API look like?

/**
 * Entities
 * Engine: Class to run live or paper trading
 * Trader: Buys and sell instruments
 * Strategy: The strategy used by a trader.
 * Resampling: For paper trading, what is the resampling strategy for paper trading periods
 * Data: Either a class with access to a market feed or historical data for paper trading.
 * Instrument: Goes into Data. Meta data about a particular instrument used for trading.
 * PerformanceMetric: How should the trader be evaluated?
 */

/**
 * All traders
 */
template <typename StratT>
class simple_trader : stonker::trader<simple_trader> {

  stonker::Strategy<StratT> strat_
  long int money_available_;

};

simple_trader<CoolStrat> trader(my_cool_strat);

using paper_instr = stonker::Instrument<stonker::Paper>
paper_instr vxx_feed("VXX", "./path/to/vxx.data");
paper_instr gme_feed("GME", "./path/to/vxx.data");
paper_instr appl_feed("APPL", "./path/to/vxx.data");

using paper_stonk = stonker::portfolio<stonker::Instrument<stonker::Paper>>;
paper_stonks the_stonks(vxx_feed, gme_feed, appl_feed);

/**
 * For Growing cross validation supply
 *   starting day: What day does the strat start?
 *   trade length: How many days should it trade for
 *   skips: How many days should be skipped in between resamples
 */
stonker::growing_cv windower(...)
stonker::Resampling<stonker::growing_cv> resamp(windower)

auto simple_backtest = stonker::backtest(trader, the_stonks, resampl, stonker::performance::roi);

simple_backtest.print_performance();
```

## Stuff for inspiration

- [mlr3](https://github.com/mlr-org/mlr3): I like their API for setting up experiments
- [PerformanceAnalytics](https://cran.r-project.org/web/packages/PerformanceAnalytics/index.html)
- [quantstat](https://github.com/braverock/quantstrat)
- [rqalpha](https://github.com/ricequant/rqalpha)

### Dependencies?

- [quantlib](https://www.quantlib.org/)
- [boost](boost.org)
- [ta-lib?](https://sourceforge.net/projects/ta-lib/)

To build: `mkdir build && cd build && cmake .. && make`

To test: `cd build && ctest`
