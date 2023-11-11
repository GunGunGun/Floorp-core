## MEMO


```JS
/* eslint-disable no-undef */

BrowserPageActions.launchSSB = {
  async onCommand(event, buttonNode) {
    if (!gBrowser.currentURI.schemeIs("https")) {
      return;
    }

    let ssb = await SiteSpecificBrowser.createFromBrowser(
      gBrowser.selectedBrowser
    );

    // Launching through the UI implies installing.
    await ssb.install();

    // The site's manifest may point to a different start page so explicitly
    // open the SSB to the current page.
    ssb.launch(gBrowser.selectedBrowser.currentURI);
    gBrowser.removeTab(gBrowser.selectedTab, { closeWindowWithLastTab: false });
  },
};

/*

const { SiteSpecificBrowser } = ChromeUtils.import(
  "resource:///modules/SiteSpecificBrowserService.jsm"
);

var a = await SiteSpecificBrowser.createFromBrowser(gBrowser.selectedBrowser)

await a.install() 

*/
```