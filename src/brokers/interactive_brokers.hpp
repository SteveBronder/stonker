#ifndef SRC_BROKERS_INTERACTIVE_BROKERS_HPP
#define SRC_BROKERS_INTERACTIVE_BROKERS_HPP

#include <stonker/brokers/broker_base.hpp>

#include <ibroker/client/StdAfx.h>

#include <ibroker/client/EWrapper.h>
#include <ibroker/client/EReaderOSSignal.h>
#include <ibroker/client/EReader.h>
#include <ibroker/client/EClientSocket.h>
#include <ibroker/client/EPosixClientSocketPlatform.h>

#include <ibroker/client/Contract.h>
#include <ibroker/client/Order.h>
#include <ibroker/client/OrderState.h>
#include <ibroker/client/Execution.h>
#include <ibroker/client/CommissionReport.h>
#include <ibroker/client/ContractSamples.h>
#include <ibroker/client/OrderSamples.h>
#include <ibroker/client/ScannerSubscription.h>
#include <ibroker/client/ScannerSubscriptionSamples.h>
#include <ibroker/client/executioncondition.h>
#include <ibroker/client/PriceCondition.h>
#include <ibroker/client/MarginCondition.h>
#include <ibroker/client/PercentChangeCondition.h>
#include <ibroker/client/TimeCondition.h>
#include <ibroker/client/VolumeCondition.h>
#include <ibroker/client/AvailableAlgoParams.h>
#include <ibroker/client/FAMethodSamples.h>
#include <ibroker/client/CommonDefs.h>
#include <ibroker/client/AccountSummaryTags.h>
#include <ibroker/client/Utils.h>

#include <stdio.h>
#include <chrono>
#include <iostream>
#include <thread>
#include <ctime>
#include <fstream>
#include <cstdint>


namespace stonker::broker {


  //! [ewrapperimpl]
class interactive_brokers : public broker_base<interactive_brokers> {
  //! [ewrapperimpl]
  public:
  	interactive_brokers();
  	~interactive_brokers();

  	void setConnectOptions(const std::string&);
  	void processMessages();

  public:

  	bool connect(const char * host, int port, int clientId = 0);
  	void disconnect() const;
  	bool isConnected() const;

  private:
      void pnlOperation();
      void pnlSingleOperation();
  	void tickDataOperation();
  	void tickOptionComputationOperation();
  	void delayedTickDataOperation();
  	void marketDepthOperations();
  	void realTimeBars();
  	void marketDataType();
  	void historicalDataRequests();
  	void optionsOperations();
  	void accountOperations();
  	void orderOperations();
  	void ocaSamples();
  	void conditionSamples();
  	void bracketSample();
  	void hedgeSample();
  	void contractOperations();
  	void marketScanners();
  	void fundamentals();
  	void bulletins();
  	void testAlgoSamples();
  	void financialAdvisorOrderSamples();
  	void financialAdvisorOperations();
  	void testDisplayGroups();
  	void miscelaneous();
  	void reqFamilyCodes();
  	void reqMatchingSymbols();
  	void reqMktDepthExchanges();
  	void reqNewsTicks();
  	void reqSmartComponents();
  	void reqNewsProviders();
  	void reqNewsArticle();
  	void reqHistoricalNews();
  	void reqHeadTimestamp();
  	void reqHistogramData();
  	void rerouteCFDOperations();
  	void marketRuleOperations();
  	void continuousFuturesOperations();
      void reqHistoricalTicks();
      void reqTickByTickData();
  	void whatIfSamples();

  	void reqCurrentTime();

  public:
  	// events
  	#include "EWrapper_prototypes.h"


  private:
  	void printContractMsg(const Contract& contract);
  	void printContractDetailsMsg(const ContractDetails& contractDetails);
  	void printContractDetailsSecIdList(const TagValueListSPtr &secIdList);
  	void printBondContractDetailsMsg(const ContractDetails& contractDetails);

  private:
  	//! [socket_declare]
  	EReaderOSSignal m_osSignal;
  	std::unique_ptr<EClientSocket> m_pClient;
  	//! [socket_declare]
  	State m_state;
  	time_t m_sleepDeadline;

  	OrderId m_orderId;
  	std::unique_ptr<EReader> m_pReader;
      bool m_extraAuth;
  	std::string m_bboExchange;
  };

}

#endif
