/**
 * Copyright (c) 2017-present, Facebook, Inc.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

const React = require('react');

class Footer extends React.Component {
  render() {
    return (
      <footer className="nav-footer" id="footer">
        <div className="footer">
          <a
            href="https://haptik.ai/"
            target="_blank"
            rel="noreferrer noopener"
            className="fbOpenSource"
          >
            <img
              src={`${this.props.config.baseUrl}img/image_0.png`}
              alt="Haptik Inc."
              width="100"
            />
          </a>
          <div className="footer-columns">
            {this.renderFooterColumn('Getting Started', [
              { title: 'Product Overview' },
              { title: 'Technical Overview' }
            ])}
            {this.renderFooterColumn('Tools', [
              { title: 'Bot Builder' },
              { title: 'Agent Chat' },
              { title: 'Analytics' }
            ])}
            {this.renderFooterColumn('Integrations', [
              { title: 'iOS SDK' },
              { title: 'Android SDK' },
              { title: 'Web SDK' },
              { title: 'Webhooks' },
              { title: 'HSL' }
            ])}
            {this.renderFooterColumn('Misc', [
              { title: 'Security' },
              { title: 'Support' },
              { title: 'SLA' }
            ])}
          </div>
          <div className="footer-copyright" />
        </div>
        <section className="copyright">{this.props.config.copyright}</section>
      </footer>
    );
  }

  renderFooterColumn(title, links) {
    return (
      <div className="footer-column">
        <div className="footer-column-title">{title}</div>
        <div className="footer-column-links">
          {links.map((link, i) => (
            <a key={i} href={link.url} className="footer-column-link">
              {link.title}
            </a>
          ))}
        </div>
      </div>
    );
  }
}

module.exports = Footer;
