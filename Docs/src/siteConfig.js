/**
 * Copyright (c) 2017-present, Facebook, Inc.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

// See https://docusaurus.io/docs/site-config.html for all the possible
// site configuration options.

const siteConfig = {
  title: 'Haptik iOS SDK' /* title for your website */,
  tagline: 'Integration Documentation',
  url: 'https://hellohaptik.github.io/' /* your website url */,
  baseUrl: '/HaptikLib-iOS/' /* base url for your project */,
  cleanUrl: true,
  projectName: 'HaptikLib-iOS',
  organizationName: 'hellohaptik',

  headerLinks: [
    {
      href: '/docs_haptik/#getting-started',
      label: 'Getting Started'
    },
    {
      href: '/docs_haptik/#tools',
      label: 'Tools'
    },
    {
      href: '/docs_haptik/#integrations',
      label: 'Integrations'
    }
  ],

  headerIcon: 'img/image_0.png',
  footerIcon: 'img/image_0.png',
  favicon: 'img/image_0.png',

  colors: {
    primaryColor: '#333',
    secondaryColor: '#205C3B'
  },

  // This copyright info is used in /core/Footer.js and blog rss/atom feeds.
  copyright: `Copyright © ${new Date().getFullYear()} Haptik Inc.`,

  highlight: {
    // Highlight.js theme to use for syntax highlighting in code blocks
    theme: 'default'
  },

  // Add custom scripts here that would be placed in <script> tags
  scripts: [],

  /* On page navigation for the current documentation page */
  onPageNav: 'separate',

  /* Open Graph and Twitter card images */
  ogImage: 'img/image_0.png',
  twitterImage: 'img/image_0.png',

  customDocsPath: 'pages',
  enableUpdateTime: true,
  docsUrl: '',
  fonts: {
    myFont: ['Roboto', 'sans-serif'],
    myOtherFont: ['Roboto', 'sans-serif']
  },

  gaTrackingId: 'UA-106563119-5'

  // You may provide arbitrary config keys to be used as needed by your
  // template. For example, if you need your repo's URL...
  //   repoUrl: 'https://github.com/facebook/test-site',
};

module.exports = siteConfig;
