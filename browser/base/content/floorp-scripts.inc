# -*- Mode: Java; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

<script type="text/javascript">
// "FloorpAppConstants" has build information.
var { FloorpAppConstants } = ChromeUtils.importESModule(
    "resource:///modules/FloorpAppConstants.sys.mjs"
);

Services.scriptloader.loadSubScript("chrome://browser/content/browser-command.js", this);
Services.scriptloader.loadSubScript("chrome://browser/content/browser-overrides.js", this);

if (!FloorpAppConstants.FLOORP_LIGHTNING_BUILD) {
    Services.scriptloader.loadSubScript("chrome://browser/content/browser-design.js", this);
    Services.scriptloader.loadSubScript("chrome://browser/content/browser-rest-mode.js", this);
}

// This function is called when the floorp browser window is loaded. needs Delay.
document.addEventListener("DOMContentLoaded", () => {

    Services.scriptloader.loadSubScript("chrome://browser/content/browser-context-menu.js", this);
    Services.scriptloader.loadSubScript("chrome://browser/content/browser-manager-sidebar.js", this);
    Services.scriptloader.loadSubScript("chrome://browser/content/browser-preferences.js", this);
    Services.scriptloader.loadSubScript("chrome://browser/content/browser-workspace.js", this);
    Services.scriptloader.loadSubScript("chrome://browser/content/browser-private-container.js", this);
    Services.scriptloader.loadSubScript("chrome://browser/content/browser-statusbar.js", this);

    if (!FloorpAppConstants.FLOORP_LIGHTNING_BUILD) {
        // Floorp Browser needs the following scripts. Not Lightning Build.
        Services.scriptloader.loadSubScript("chrome://browser/content/browser-custom-keyboard-shortcut.js", this);
        Services.scriptloader.loadSubScript("chrome://browser/content/browser-downloadbar.js", this);
        Services.scriptloader.loadSubScript("chrome://browser/content/browser-favicon-color.js", this);
        Services.scriptloader.loadSubScript("chrome://browser/content/browser-UI-custom.js", this);
        Services.scriptloader.loadSubScript("chrome://browser/content/browser-splitView.js", this);
        Services.scriptloader.loadSubScript("chrome://browser/content/browser-browserActions.js", this);
        Services.scriptloader.loadSubScript("chrome://browser/content/browser-pageActions-floorp.js", this);
        Services.scriptloader.loadSubScript("chrome://browser/content/browser-pinned-tabs-title.js", this);
        Services.scriptloader.loadSubScript("chrome://browser/content/browser-chromeCSS.js", this);
    }

    // If script need more delay, use the following code.

    //Lightning Build
    SessionStore.promiseInitialized.then(() => {
        if (!FloorpAppConstants.FLOORP_LIGHTNING_BUILD) {
            Services.scriptloader.loadSubScript("chrome://browser/content/browser-UI-customizing-menu.js", this);
            Services.scriptloader.loadSubScript("chrome://browser/content/browser-tabbar.js", this);
            Services.scriptloader.loadSubScript("chrome://browser/content/browser-verticaltabs.js", this);
        }

        // lightning build and normal build
        Services.scriptloader.loadSubScript("chrome://browser/content/browser-flex-order.js", this);
    });
}, { once: true });
</script>
