/*!
 \file   branding.cpp
 \brief  Implementation of Global Constants t control apearance / branding
 \author J Cole-Baker (For Smartest)
 \date   Jan 2015

 This file provides implementation for some global constants which control app appearance.
 It's really part of the "globals" class but the code has been placed here for convenience.

 Note we select brand at build time by using #define, so that the alternate branding
 information is not included in the final binary!

 Brand Select #defines:
   BRAND_CEYEAR   - CEYear
   BRAND_COHERENT - Coherent Solutions

   [none]         - Default to "SmarTest"

*/

#include "globals.h"

#ifdef BRAND_CEYEAR
 // CE Year Branding:
 #define TEXT_COLOR_CSS "black"
 const bool    globals::USE_CHANNEL_BG_COLORS = true;

 const QString globals::BRAND           = QString("CeYear");
 const QString globals::APP_TITLE       = QString("CeYear 5233D-S");
 const QString globals::BUILD_MODEL     = QString("5233D-S");

 const QString globals::LOGO_FILE_SMALL = QString(":/CeYearLogo.png");
 const QSize   globals::LOGO_SIZE_SMALL = QSize(151, 30);
 const QString globals::LOGO_FILE_LARGE = QString(":/CeYearLogoLarge.png");
 const QSize   globals::LOGO_SIZE_LARGE = QSize(240, 47);

 const QString globals::BG_STYLESHEET = QString("");

 const QString globals::UI_STYLESHEET = QString(
             " BertUICheckBox { color: " TEXT_COLOR_CSS " } "
             " BertUIGroup    { color: " TEXT_COLOR_CSS " } "
             " BertUILabel    { color: " TEXT_COLOR_CSS " } "
             " BertUITextInfo "
             " { "
             "  border: 1px solid black; "
             "  background-color: white; "
             "  color: " TEXT_COLOR_CSS " "
             " } "
             );

 const QString globals::MAIN_TAB_STYLE = QString(" QTabWidget::pane            "
                                                 " {                           "
                                                 "   background: transparent;  "
                                                 "   color: black;             "
                                                 "   border: 1px solid black;  "
                                                 " }                           ");

 const QString globals::ABOUT_BLURB = QString(
             "<html><head/>"
             "<body>"
             "<p><strong>Notice:</strong></p>"
             "<p>"
             "    No part of this software may be reproduced in any form or by any means "
             "    (including electronic storage and retrieval) without prior agreement and "
             "    written consent from CeYear as governed by international copyright laws. "
             "</p>"
             "<p>© CeYear 2018</p>"
             "</html>"
             );

 #define BRANDED 1
#endif

#define BRAND_COHERENT
#ifdef BRAND_COHERENT
 // Coherent Solutions Branding:
 #define TEXT_COLOR_CSS "#262464"
 const bool    globals::USE_CHANNEL_BG_COLORS = false;
 const QString globals::BRAND           = QString("Coherent Solutions");
 const QString globals::APP_TITLE       = QString("Coherent Solutions PPG/BERT");
 const QString globals::BUILD_MODEL     = QString("");

 const QString globals::LOGO_FILE_SMALL = QString(":/CoherentLogoLarge.png"); // CoherentLogoSmall.png
 const QSize   globals::LOGO_SIZE_SMALL = QSize(75, 30);
 const QString globals::LOGO_FILE_LARGE = QString(":/CoherentLogoLarge.png");
 const QSize   globals::LOGO_SIZE_LARGE = QSize(249, 100);

 const QString globals::BG_STYLESHEET = QString(
             " BertUIBGWidget { background-color: white } "
             );

 // UI Stylesheet: Generic style sheet which covers many widgets;
 // Branding-specific styling inserted here.
 const QString globals::UI_STYLESHEET = QString(
             " BertUICheckBox { color: " TEXT_COLOR_CSS " } "
             " BertUIGroup    { color: " TEXT_COLOR_CSS " } "
             " BertUILabel    { color: " TEXT_COLOR_CSS " } "
             " BertUITextInfo "
             " { "
             "  border: 1px solid black; "
             "  background-color: white; "
             "  color: " TEXT_COLOR_CSS " "
             " } "
             );

 // Stylesheet specific to Tab widget:
 const QString globals::MAIN_TAB_STYLE = QString(" QTabWidget::pane             "
                                                 " {                            "
                                                 "   background: white;         "
                                                 "   color: " TEXT_COLOR_CSS "; "
                                                 "   border: 1px solid black;   "
                                                 "   position: absolute; top: -1px; "
                                                 " }                            "
                                                 " QTabBar::tab                 "
                                                 " {                            "
                                                 "   padding: 2px 5px 2px; "
                                                 "   border-top: 1px solid " TEXT_COLOR_CSS "; "
                                                 "   border-left: 1px solid " TEXT_COLOR_CSS "; "
                                                 "   border-right: 1px solid " TEXT_COLOR_CSS "; "
                                                 "   border-bottom: 1px solid " TEXT_COLOR_CSS "; "
                                                 "   border-top-left-radius: 8px; "
                                                 "   border-top-right-radius: 8px; "
                                                 "   color: " TEXT_COLOR_CSS ";  "
                                                 "   background: #ffffff; "
                                                 " } "
                                                 " QTabBar::tab:selected "
                                                 " { "
                                                 "   color: " TEXT_COLOR_CSS "; "
                                                 "   background-color: #ffffff; "
                                                 "   border-bottom: 1px solid white; "
                                                 " } "
                                                 );

 const QString globals::ABOUT_BLURB = QString(
             "<html><head/>"
             "<body>"
             "<p><strong>Notice:</strong></p>"
             "<p>"
             "    No part of this software may be reproduced in any form or by any means "
             "    (including electronic storage and retrieval) without prior agreement and "
             "    written consent from Coherent Solutions as governed by international copyright laws. "
             "</p>"
             "<p>© Coherent Solutions 2018</p>"
             "</html>"
             );

 #define BRANDED 1
#endif

#ifndef BRANDED  // No branding specified.
 // Smartest Branding: This is the default if no brand specified for build
 #define TEXT_COLOR_CSS "black"
 const bool    globals::USE_CHANNEL_BG_COLORS = true;

 const QString globals::BRAND           = QString("SmarTest");
 const QString globals::APP_TITLE       = QString("SmarTest Desktop");
 const QString globals::BUILD_MODEL     = QString("");                // Applies to CEYear brand ONLY; Smartest build is not model specific.

 const QString globals::LOGO_FILE_SMALL = QString(":/SmartestLogoSmall.png");
 const QSize   globals::LOGO_SIZE_SMALL = QSize(101, 32);
 const QString globals::LOGO_FILE_LARGE = QString(":/SmartestLogoSmall.png");
 const QSize   globals::LOGO_SIZE_LARGE = QSize(318, 100);

 const QString globals::BG_STYLESHEET = QString("");

 const QString globals::UI_STYLESHEET = QString(
             " BertUICheckBox { color: " TEXT_COLOR_CSS " } "
             " BertUIGroup    { color: " TEXT_COLOR_CSS " } "
             " BertUILabel    { color: " TEXT_COLOR_CSS " } "
             " BertUITextInfo "
             " { "
             "  border: 1px solid black; "
             "  background-color: white; "
             "  color: " TEXT_COLOR_CSS " "
             " } "
             );

 const QString globals::MAIN_TAB_STYLE = QString(" QTabWidget::pane            "
                                                 " {                           "
                                                 "   background: transparent;  "
                                                 "   color: black;             "
                                                 "   border: 1px solid black;  "
                                                 " }                           ");

 const QString globals::ABOUT_BLURB = QString(
             "<html><head/>"
             "<body>"
             "<p><strong>Notice:</strong></p>"
             "<p>"
             "    No part of this software may be reproduced in any form or by any means "
             "    (including electronic storage and retrieval) without prior agreement and "
             "    written consent from Smart Test Electronics as governed by international "
             "    copyright laws. "
             "</p>"
             "<p>© Smart Test Electronics 2018</p>"
             "</html>"
             );
#endif
