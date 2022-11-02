//
//  MBIssuer.h
//  BlinkShowcaseDev
//
//  Created by Jura Skrlec on 02/11/2020.
//

#ifndef MBIssuer_h
#define MBIssuer_h

typedef NS_ENUM(NSInteger, MBIssuer) {
    /* Unidentified Card */
    MBIssuerOther = 0,
    /* The American Express Company Card */
    MBIssuerAmericanExpress,
    /* China UnionPay Card */
    MBIssuerChinaUnionPay,
    /* Diners Club International Card */
    MBIssuerDiners,
    /* Discover Card */
    MBIssuerDiscoverCard,
    /* Elo card association */
    MBIssuerElo,
    /* The JCB Company Card */
    MBIssuerJcb,
    /* Maestro Debit Card */
    MBIssuerMaestro,
    /* Mastercard Inc. Card */
    MBIssuerMastercard,
    /* RuPay */
    MBIssuerRuPay,
    /* Interswitch Verve Card */
    MBIssuerVerve,
    /* Visa Inc. Card */
    MBIssuerVisa,
    /* VPay */
    MBIssuerVPay
};

#endif /* MBIssuer_h */
