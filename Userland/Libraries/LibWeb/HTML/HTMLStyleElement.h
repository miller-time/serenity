/*
 * Copyright (c) 2018-2021, Andreas Kling <kling@serenityos.org>
 * Copyright (c) 2021, the SerenityOS developers.
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <LibWeb/HTML/HTMLElement.h>

namespace Web::HTML {

class HTMLStyleElement final : public HTMLElement {
    WEB_PLATFORM_OBJECT(HTMLStyleElement, HTMLElement);

public:
    virtual ~HTMLStyleElement() override;

    virtual void children_changed() override;
    virtual void inserted() override;
    virtual void removed_from(Node*) override;

    void update_a_style_block();

    CSS::CSSStyleSheet* sheet();
    CSS::CSSStyleSheet const* sheet() const;

private:
    HTMLStyleElement(DOM::Document&, DOM::QualifiedName);

    virtual void visit_edges(Cell::Visitor&) override;

    // https://www.w3.org/TR/cssom/#associated-css-style-sheet
    JS::GCPtr<CSS::CSSStyleSheet> m_associated_css_style_sheet;
};

}

WRAPPER_HACK(HTMLStyleElement, Web::HTML)
