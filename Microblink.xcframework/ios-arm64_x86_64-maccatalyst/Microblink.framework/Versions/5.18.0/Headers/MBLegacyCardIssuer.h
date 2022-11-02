//
//  MBPaymentLegacyCardIssuer.h
//  MicroBlink
//
//  Created by Jura on 07/02/2019.
//

#ifndef MBLegacyCardIssuer_h
#define MBLegacyCardIssuer_h

typedef NS_ENUM(NSInteger, MBLegacyCardIssuer) {
    /* Unidentified Card */
    MBLegacyCardIssuerOther = 0,
    /* The American Express Company Card */
    MBLegacyCardIssuerAmericanExpress,
    /* The Bank of Montreal ABM Card */
    MBLegacyCardIssuerBmoAbm,
    /* China T-Union Transportation Card */
    MBLegacyCardIssuerChinaTUnion,
    /* China UnionPay Card */
    MBLegacyCardIssuerChinaUnionPay,
    /* Canadian Imperial Bank of Commerce Advantage Debit Card */
    MBLegacyCardIssuerCibcAdvantageDebit,
    /* CISS Card */
    MBLegacyCardIssuerCiss,
    /* Diners Club International Card */
    MBLegacyCardIssuerDinersClubInternational,
    /* Diners Club United States & Canada Card */
    MBLegacyCardIssuerDinersClubUsCanada,
    /* Discover Card */
    MBLegacyCardIssuerDiscoverCard,
    /* HSBC Bank Canada Card */
    MBLegacyCardIssuerHsbc,
    /* RuPay Card */
    MBLegacyCardIssuerRuPay,
    /* InterPayment Card */
    MBLegacyCardIssuerInterPayment,
    /* InstaPayment Card */
    MBLegacyCardIssuerInstaPayment,
    /* The JCB Company Card */
    MBLegacyCardIssuerJcb,
    /* Laser Debit Card (deprecated) */
    MBLegacyCardIssuerLaser,
    /* Maestro Debit Card */
    MBLegacyCardIssuerMaestro,
    /* Dankort Card */
    MBLegacyCardIssuerDankort,
    /* MIR Card */
    MBLegacyCardIssuerMir,
    /* MasterCard Inc. Card */
    MBLegacyCardIssuerMasterCard,
    /* The Royal Bank of Canada Client Card */
    MBLegacyCardIssuerRbcClient,
    /* ScotiaBank Scotia Card */
    MBLegacyCardIssuerScotiaBank,
    /* TD Canada Trust Access Card */
    MBLegacyCardIssuerTdCtAccess,
    /* Troy Card */
    MBLegacyCardIssuerTroy,
    /* Visa Inc. Card */
    MBLegacyCardIssuerVisa,
    /* Universal Air Travel Plan Inc. Card */
    MBLegacyCardIssuerUatp,
    /* Interswitch Verve Card */
    MBLegacyCardIssuerVerve
};

#endif /* MBPaymentLegacyCardIssuer_h */
